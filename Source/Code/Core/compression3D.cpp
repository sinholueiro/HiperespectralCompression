#include "utils3D.h"
#include "callback.h"

#include <cstdio>
#include <cstdlib>
#include <sys/stat.h>
#include <inttypes.h>

void compression3D(char *input, char *output, int w, int h, int comp, int depth, int s, int endian, int bsq){
    opj_cparameters_t parameters;
    opj_event_mgr_t event_mgr;
    opj_volume_t *volume = NULL;

    memset(&event_mgr, 0, sizeof(opj_event_mgr_t));
    event_mgr.error_handler = error_callback;
    event_mgr.warning_handler = warning_callback;
    event_mgr.info_handler = info_callback;

    opj_set_default_encoder_parameters3D(&parameters);
    opj_strcpy_s(parameters.outfile, sizeof(parameters.outfile), output);
    opj_strcpy_s(parameters.infile, sizeof(parameters.infile), input);

    if (parameters.tcp_numlayers == 0) {
        parameters.tcp_rates[0] = 0.0;
        parameters.tcp_numlayers++;
        parameters.cp_disto_alloc = 1;
    }

    parameters.encoding_format = ENCOD_3EB;

    int codestream_length, pixels, bitsin;
    opj_cio_t *cio = NULL;
    FILE *f = NULL;
    opj_cinfo_t* cinfo = NULL;

    volume = bintovolume(input,w,h,comp,depth,s,endian,&parameters);

    if(bsq==0){
        bip2bsq3D(volume,comp);
    }

    cinfo = opj_create_compress3D(CODEC_J3D);
    opj_set_event_mgr((opj_common_ptr)cinfo, &event_mgr, stdout);

    opj_setup_encoder3D(cinfo, &parameters, volume);

    cio = opj_cio_open((opj_common_ptr)cinfo, NULL, 0);

    opj_encode3D(cinfo, cio, volume, parameters.index);

    codestream_length = cio_tell(cio);
    pixels =(volume->x1 - volume->x0) * (volume->y1 - volume->y0) * (volume->z1 - volume->z0);
    bitsin = pixels * volume->comps[0].prec;

    f = fopen(parameters.outfile, "wb");
    fwrite(cio->buffer, 1, codestream_length, f);
    fclose(f);

    //Metricas
    struct stat st;
    stat(input, &st);
    float sizeratio = (intmax_t)st.st_size;
    printf("%jd\n",(intmax_t)st.st_size);
    float bitrate = ((intmax_t)st.st_size*8) / comp;
    bitrate = bitrate / w / h;
    printf("%lf\n",bitrate);

    stat(output, &st);
    printf("%jd\n",(intmax_t)st.st_size);
    bitrate = ((intmax_t)st.st_size*8) / comp;
    bitrate = bitrate / w / h;
    printf("%lf\n",bitrate);

    printf("%f\n",(sizeratio/(intmax_t)st.st_size)*100);

    float mseResult=mse3D(parameters,*volume,comp,bsq,endian);
    printf("%lf\n",mseResult);
    printf("%lf\n",psnr3D(*volume,mseResult));

    opj_cio_close(cio);
    opj_destroy_compress(cinfo);
    opj_volume_destroy(volume);
}