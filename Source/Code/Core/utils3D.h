#ifndef TRESD_H
#define TRESD_H

#include "lib3D/openjp3d.h"
#include "lib3D/convert.h"
#include "lib3D/opj_string.h"

void bip2bsq3D(opj_volume_t *imagen, int comps);
float mse3D(opj_cparameters_t parametros, opj_volume_t original,int comp,int bsq,int endian);
float psnr3D(opj_volume_t volumen, float mse);

void compression3D(char *input, char *output, int w, int h, int comp, int depth, int s, int endian, int bsq);

#endif