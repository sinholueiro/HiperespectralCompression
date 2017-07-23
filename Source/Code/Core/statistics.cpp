#include "utils2D.h"
#include "callback.h"

//MeanSquaredError
float mse(opj_cparameters_t parametros, raw_cparameters_t rawp, int bsq, int endian){
    float auxResultado, resultado = 0;
    int i,j;

    //Lectura de imagen comprimida
    opj_decompress_parameters parametrosReverse;
    opj_image_t *comprimida = NULL;
    opj_stream_t *l_stream = NULL;
    opj_codec_t *l_codec = NULL;

    memset(&parametrosReverse, 0, sizeof(opj_decompress_parameters));
    opj_set_default_decoder_parameters((opj_dparameters_t *)&parametrosReverse);
    parametrosReverse.tile_index=3;
    parametrosReverse.nb_tile_to_decode = 1;

    opj_strcpy_s(parametrosReverse.infile, sizeof(parametrosReverse.infile), parametros.outfile);
    opj_strcpy_s(parametrosReverse.outfile, sizeof(parametrosReverse.outfile), parametros.infile);

    l_stream = opj_stream_create_default_file_stream(parametrosReverse.infile,1);
    l_codec = opj_create_decompress(OPJ_CODEC_JP2);

    opj_set_info_handler(l_codec, info_callback,00);
    opj_set_warning_handler(l_codec,warning_callback,00);
    opj_set_error_handler(l_codec,error_callback,00);

    opj_setup_decoder(l_codec,&parametrosReverse.core);
    opj_codec_set_threads(l_codec, parametrosReverse.num_threads);
    opj_read_header(l_stream,l_codec,&comprimida);

    opj_decode(l_codec, l_stream, comprimida);
    opj_end_decompress(l_codec,	l_stream);

    char *str;
    str=(char *)malloc(sizeof(char)*3);
    sprintf(str,"%s",".raw");
    strcat(parametrosReverse.infile,str);

    if(endian==1){
        imagetorawl(comprimida,parametrosReverse.infile);
    }else{
        imagetoraw(comprimida,parametrosReverse.infile);
    }

    //Lectura de imagen original
    opj_image_t *imagen;
    if(endian==1){
        imagen = rawltoimage(parametros.infile,&parametros,&rawp);
    }else{
        imagen = rawtoimage(parametros.infile,&parametros,&rawp);
    }

    if(bsq==0){
        bip2bsq(imagen);
    }

    for(i=0;i<imagen->numcomps;i++){
        for(j=0;j<imagen->comps->h*imagen->comps->w;j++){
            //Diferencia^2
            auxResultado = imagen->comps[i].data[j];
            auxResultado -= comprimida->comps[i].data[j];
            auxResultado = auxResultado * auxResultado;
            //Sumatorio
            resultado += auxResultado;
        }
    }

    //División entre tamaño de imagen y componentes
    resultado = resultado/imagen->comps->w/imagen->comps->h/imagen->numcomps;

    free(comprimida);
    free(l_stream);
    free(l_codec);
    free(imagen);

    return resultado;
}

float msePiezas(opj_cparameters_t parametros, raw_cparameters_t rawp, int componentes, int bsq, int endian){
    float auxResultado, resultado = 0;
    int i;

    //Lectura de imagen original
    opj_image_t *imagen;
    if(endian==1){
        imagen = rawltoimage(parametros.infile,&parametros,&rawp);
    }else{
        imagen = rawtoimage(parametros.infile,&parametros,&rawp);
    }


    if(bsq==0){
        bip2bsq(imagen);
    }

    //Lectura de imagen comprimida
    opj_decompress_parameters parametrosReverse;
    opj_image_t *comprimida = NULL;
    opj_stream_t *l_stream = NULL;
    opj_codec_t *l_codec = NULL;

    memset(&parametrosReverse, 0, sizeof(opj_decompress_parameters));
    opj_set_default_decoder_parameters((opj_dparameters_t *)&parametrosReverse);

    opj_strcpy_s(parametrosReverse.outfile, sizeof(parametrosReverse.outfile), parametros.infile);

    char *str;
    str=(char *)malloc(sizeof(char)*3);
    int parted=0;

    for(parted=0;parted<componentes;parted++){
        strcpy(parametrosReverse.infile,parametros.outfile);
        sprintf(str,"%d",parted);
        strcat(parametrosReverse.infile,str);

        l_stream = opj_stream_create_default_file_stream(parametrosReverse.infile,1);
        l_codec = opj_create_decompress(OPJ_CODEC_JP2);

        opj_set_info_handler(l_codec, info_callback,00);
        opj_set_warning_handler(l_codec,warning_callback,00);
        opj_set_error_handler(l_codec,error_callback,00);

        opj_setup_decoder(l_codec,&parametrosReverse.core);
        opj_codec_set_threads(l_codec, parametrosReverse.num_threads);
        opj_read_header(l_stream,l_codec,&comprimida);

        opj_decode(l_codec, l_stream, comprimida);
        opj_end_decompress(l_codec,	l_stream);

        for(i=0;i<imagen->comps->h*imagen->comps->w;i++){
            //Diferencia^2
            auxResultado = imagen->comps[parted].data[i];
            auxResultado -= comprimida->comps[0].data[i];

            if(imagen->comps[parted].data[i]!=comprimida->comps[0].data[i]){
                printf("%d:%d\n",parted,i);
                printf("\t%d %d\n",imagen->comps[parted].data[i],comprimida->comps[0].data[i]);
                getchar();
            }

            auxResultado = auxResultado * auxResultado;
            //Sumatorio
            resultado += auxResultado;
        }
    }

    //División entre tamaño de imagen y componentes
    resultado = resultado/imagen->comps->w/imagen->comps->h/imagen->numcomps;

    free(comprimida);
    free(l_stream);
    free(l_codec);
    free(imagen);

    return resultado;
}

//Peal Signal-to-Noise Ratio
float psnr(opj_image_t imagen, float mse){
    float resultado=10*::log((imagen.comps->bpp*imagen.comps->bpp)/mse);
    return resultado;
}