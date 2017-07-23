#include <cmath>
#include <cstdio>

void normalize(unsigned char *o_ptr, unsigned short* i_ptr, int a, int b, int w, int h, int d);
void convertBIP2BSQ(unsigned short *m_lowDetailDataTMP, unsigned short *tmp, int width, int height, int bands);
void readImage(FILE *fp, unsigned char *imageData, int width, int height, int bands, int dataSigned, int endianness, int bip2bsq);
