#include "utils3D.h"
#include "callback.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>

void bip2bsq3D(opj_volume_t *imagen, int comps){
    int *tmp;
    tmp=(int *)malloc(sizeof(int)*(imagen->comps->w * imagen->comps->h * comps));

    int i,j,k,imageSize,aux;
    imageSize = imagen->comps->w * imagen->comps->h;

    for(i=0;i<imagen->comps->h;i++){
        for(j=0;j<imagen->comps->w;j++){
            for(k=0;k<comps;k++){
                aux = i * imagen->comps->w + j;
                tmp[k*imageSize +aux] = imagen->comps->data[aux*comps+k];
            }
        }
    }

    for(i=0;i<imageSize*comps;i++){
        imagen->comps->data[i] = tmp[i];
    }
    free(tmp);
}

//MeanSquaredError
float mse3D(opj_cparameters_t parametros, opj_volume_t original, int comp, int bsq, int endian){
    float auxResultado, resultado = 0;
    int i;

    //Lectura de imagen comprimida
    opj_dparameters_t parametrosReverse;
    opj_event_mgr_t event_mgr;
    opj_volume_t *volume = NULL;

    FILE *fsrc = NULL;
    unsigned char *src = NULL;
    int file_length;

    opj_dinfo_t* dinfo = NULL;
    opj_cio_t *cio = NULL;

    memset(&event_mgr, 0, sizeof(opj_event_mgr_t));
    event_mgr.error_handler = error_callback;
    event_mgr.warning_handler = warning_callback;
    event_mgr.info_handler = info_callback;

    strcpy(parametrosReverse.original,"NULL");
    strcpy(parametrosReverse.imgfile,"NULL");
    opj_set_default_decoder_parameters3D(&parametrosReverse);
    opj_strcpy_s(parametrosReverse.infile, sizeof(parametros.outfile), parametros.outfile);
    opj_strcpy_s(parametrosReverse.outfile, sizeof(parametros.infile), parametros.infile);

    parametrosReverse.decod_format=J3D_CFMT;

    if(endian==1){
        parametrosReverse.bigendian=0;
    }else{
        parametrosReverse.bigendian=1;
    }

    fsrc = fopen(parametrosReverse.infile, "rb");
    fseek(fsrc, 0, SEEK_END);
    file_length = ftell(fsrc);
    fseek(fsrc, 0, SEEK_SET);
    src = (unsigned char *) malloc(file_length);
    fread(src, 1, file_length, fsrc);
    fclose(fsrc);

    dinfo = opj_create_decompress3D(CODEC_J3D);

    opj_set_event_mgr((opj_common_ptr)dinfo, &event_mgr, stderr);

    opj_setup_decoder3D(dinfo, &parametrosReverse);

    cio = opj_cio_open((opj_common_ptr)dinfo, src, file_length);

    volume = opj_decode3D(dinfo, cio);

    opj_cio_close(cio);
    free(src);
    src=NULL;

    if(bsq==0){
        bip2bsq3D(volume,comp);
    }

    for(i=0;i<volume->comps->w*volume->comps->h*volume->comps->l;i++){
        //Diferencia^2
        auxResultado = volume->comps->data[i];
        auxResultado -= original.comps->data[i];

        auxResultado = auxResultado * auxResultado;
        //Sumatorio
        resultado += auxResultado;
    }

    //División entre tamaño de imagen y componentes
    resultado = resultado/volume->comps->w/volume->comps->h/volume->comps->l;

    return resultado;
}

//Peal Signal-to-Noise Ratio
float psnr3D(opj_volume_t volume, float mse){
    float resultado=10*log((volume.comps->bpp*volume.comps->bpp)/mse);
    return resultado;
}