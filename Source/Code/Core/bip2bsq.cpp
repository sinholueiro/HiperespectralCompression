#include "utils2D.h"

void bip2bsq(opj_image_t *imagen){
    OPJ_INT32 *tmp;
    tmp=(OPJ_INT32 *)malloc(sizeof(OPJ_INT32)*(imagen->comps->w * imagen->comps->h * imagen->numcomps));

    int i,j,k,imageSize,aux;
    imageSize = imagen->comps->w * imagen->comps->h;

    for(i=0;i<imagen->comps->h;i++){
        for(j=0;j<imagen->comps->w;j++){
            for(k=0;k<imagen->numcomps;k++){
                aux = i * imagen->comps->w + j;
                tmp[k * imagen->comps->h * imagen->comps->w + aux] =
                    imagen->comps[((aux * imagen->numcomps + k) / imageSize)].data[ (aux * imagen->numcomps + k) % imageSize ];
            }
        }
    }

    for(i=0;i<imagen->numcomps;i++){
        for(j=0;j<imageSize;j++) {
            imagen->comps[i].data[j] = tmp[j + i*imageSize];
        }
    }
}