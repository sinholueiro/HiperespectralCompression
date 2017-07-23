#include "utils2D.h"

//Configuración de parámetros para lossless compression
void decodeRight(opj_cparameters_t *parametros, raw_cparameters_t *rawp, int w, int h, int comp, int depth, int s){
    int i=0;

    // Seteo de lossless
    if (parametros->tcp_numlayers == 0) {
        parametros->tcp_rates[0] = 0;
        parametros->tcp_numlayers++;
        parametros->cp_disto_alloc = 1;
    }

    rawp->rawWidth=w;
    rawp->rawHeight=h;
    rawp->rawComp=comp;
    rawp->rawBitDepth=depth;
    if(s==0){
        rawp->rawSigned = OPJ_FALSE;
    }else{
        rawp->rawSigned = OPJ_TRUE;
    }

    rawp->rawComps=(raw_comp_cparameters_t *)malloc(((OPJ_UINT16)(comp))*sizeof(raw_comp_cparameters_t));

    for(i=0;i<comp;i++){
        rawp->rawComps[i].dx=1;
        rawp->rawComps[i].dy=1;
    }
}