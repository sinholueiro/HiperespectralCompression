#include "utils2D.h"
#include "callback.h"

void compression2D(char *input, char *output, int w, int h, int comp, int depth, int s, int endian, int bsq, int parted) {
    //Parámetros iniciales
    opj_cparameters_t parametros;
    raw_cparameters_t rawp;
    opj_stream_t *l_stream = 00;
    opj_codec_t *l_codec = 00;

    //Setup parámetros por defecto
    opj_set_default_encoder_parameters(&parametros);

    //Imagen IO
    opj_image_t *imagen = NULL;
    parametros.decod_format=RAW_DFMT;
    parametros.cod_format=JP2_CFMT;

    opj_strcpy_s(parametros.infile, sizeof(parametros.infile), input);
    opj_strcpy_s(parametros.outfile, sizeof(parametros.outfile), output);

    //Mod parámetros
    decodeRight(&parametros,&rawp,w,h,comp,depth,s);

    //Lectura de imagen
    if(endian==1){
        imagen = rawltoimage(parametros.infile, &parametros, &rawp);
    }else{
        imagen = rawtoimage(parametros.infile, &parametros, &rawp);
    }
    if(bsq==0){
        bip2bsq(imagen);
    }
    int imagenSize = imagen->comps->w * imagen->comps->h;

    if(parted==1){
        int tmpcomps = imagen->numcomps;
        imagen->numcomps=1;
        char outfileAux[4096];
        char *str;
        str=(char *)malloc(sizeof(char)*3);
        strcpy(outfileAux,parametros.outfile);

        struct stat st;
        int sumPiezas=0;
        int *backup;
        backup=(OPJ_INT32 *)malloc(sizeof(OPJ_INT32)*imagenSize);
        backup=imagen->comps[0].data;

        for(parted=0;parted<tmpcomps;parted++){
            //Preparación de la salida
            strcpy(parametros.outfile,outfileAux);
            sprintf(str,"%d",parted);
            strcat(parametros.outfile,str);

            imagen->comps[0].data=imagen->comps[parted].data;

            //Parámetro de salida
            l_codec = opj_create_compress(OPJ_CODEC_JP2);

            //Añadir handlers a l_codec
            opj_set_info_handler(l_codec, info_callback, 00);
            opj_set_warning_handler(l_codec, warning_callback, 00);
            opj_set_error_handler(l_codec, error_callback, 00);

            //Preparación del encoder
            opj_setup_encoder(l_codec, &parametros, imagen);
            l_stream = opj_stream_create_default_file_stream(parametros.outfile, OPJ_FALSE);

            //Compress imagen
            opj_start_compress(l_codec, imagen, l_stream);
            opj_encode(l_codec, l_stream);
            opj_end_compress(l_codec, l_stream);

            stat(parametros.outfile,&st);
            sumPiezas += (intmax_t)st.st_size;
        }
        imagen->numcomps=tmpcomps;
        strcpy(parametros.outfile,outfileAux);
        imagen->comps[0].data=backup;
        free(backup);
        free(str);

        //Metricas
        stat(input, &st);
        float sizeratio = (intmax_t)st.st_size;
        printf("%jd\n",sizeratio);
        float bitrate = (sizeratio*8) / tmpcomps;
        bitrate = bitrate / imagenSize;
        printf("%lf\n",bitrate);

        printf("%jd\n",sumPiezas);
        bitrate = (sumPiezas*8) / tmpcomps;
        bitrate = bitrate / imagenSize;
        printf("%lf\n",bitrate);

        printf("%f%\n",(sizeratio/sumPiezas)*100);

        float mseResult=msePiezas(parametros,rawp,imagen->numcomps,bsq,endian);
        printf("%lf\n",mseResult);
        printf("%lf\n",psnr(*imagen,mseResult));

        //Frees
        opj_stream_destroy(l_stream);
        opj_destroy_codec(l_codec);

    }else{
        //Parámetro de salida
        l_codec = opj_create_compress(OPJ_CODEC_JP2);

        //Añadir handlers a l_codec
        opj_set_info_handler(l_codec, info_callback, 00);
        opj_set_warning_handler(l_codec, warning_callback, 00);
        opj_set_error_handler(l_codec, error_callback, 00);

        //Preparación del encoder
        opj_setup_encoder(l_codec, &parametros, imagen);
        l_stream = opj_stream_create_default_file_stream(parametros.outfile, OPJ_FALSE);

        //Compress imagen
        opj_start_compress(l_codec, imagen, l_stream);
        opj_encode(l_codec, l_stream);
        opj_end_compress(l_codec, l_stream);

        //Metricas
        struct stat st;
        stat(input, &st);
        float sizeratio = (intmax_t)st.st_size;
        printf("%jd\n",(intmax_t)st.st_size);
        float bitrate = ((intmax_t)st.st_size*8) / (imagen->numcomps);
        bitrate = bitrate / imagenSize;
        printf("%lf\n",bitrate);

        stat(output, &st);
        printf("%jd\n",(intmax_t)st.st_size);
        bitrate = ((intmax_t)st.st_size*8) / (imagen->numcomps);
        bitrate = bitrate / imagenSize;
        printf("%lf\n",bitrate);

        printf("%f\n",(sizeratio/(intmax_t)st.st_size)*100);

        float mseResult=mse(parametros,rawp,bsq,endian);
        printf("%lf\n",mseResult);
        printf("%lf\n",psnr(*imagen,mseResult));

        //Frees
        opj_stream_destroy(l_stream);
        opj_destroy_codec(l_codec);
        opj_image_destroy(imagen);
    }
}