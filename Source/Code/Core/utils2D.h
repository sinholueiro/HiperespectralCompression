#ifndef DOSD_H
#define DOSD_H

#include "openjpeg.h"
#include "lib/convert.h"
#include "lib/format_defs.h"
#include "lib/opj_string.h"

#include <cstdlib>
#include <cmath>
#include <sys/stat.h>

typedef enum opj_prec_mode {
    OPJ_PREC_MODE_CLIP,
    OPJ_PREC_MODE_SCALE
} opj_precision_mode;

typedef struct opj_prec{
    OPJ_UINT32 prec;
    opj_precision_mode mode;
}opj_precision;

typedef struct opj_decompress_params{
    opj_dparameters_t core;

    char infile[OPJ_PATH_LEN];
    char outfile[OPJ_PATH_LEN];
    int decod_format;
    int cod_format;
    char indexfilename[OPJ_PATH_LEN];

    OPJ_UINT32 DA_x0;
    OPJ_UINT32 DA_x1;
    OPJ_UINT32 DA_y0;
    OPJ_UINT32 DA_y1;
    OPJ_BOOL m_verbose;

    OPJ_UINT32 tile_index;
    OPJ_UINT32 nb_tile_to_decode;

    opj_precision* precision;
    OPJ_UINT32     nb_precision;

    int force_rgb;
    int upsample;
    int split_pnm;
    int num_threads;
}opj_decompress_parameters;

typedef struct opj_event_mgr {
    opj_msg_callback error_handler;
    opj_msg_callback warning_handler;
    opj_msg_callback info_handler;
} opj_event_mgr_t;

void decodeRight(opj_cparameters_t *parametros, raw_cparameters_t *rawp, int w, int h, int comp, int depth, int s);

float mse(opj_cparameters_t parametros, raw_cparameters_t rawp, int bsq, int endian);
float msePiezas(opj_cparameters_t parametros, raw_cparameters_t rawp, int componentes, int bsq, int endian);
float psnr(opj_image_t imagen, float mse);

void bip2bsq(opj_image_t *imagen);

void compression2D(char *input, char *output, int w, int h, int comp, int depth, int s, int endian, int bsq, int parted);

#endif