#include <normalize.h>
#include <stdio.h>

using namespace std;

void normalize(unsigned char *o_ptr, unsigned short* i_ptr, int a, int b, int w, int h, int d){
    unsigned short A = 255, B = 0;

    for (int x = 0; x < h*w*d; ++x){
        A = (i_ptr[ x ] < A) ? i_ptr[ x ] : A; // A
        B = (i_ptr[ x ] > B) ? i_ptr[ x ] : B; // B
    }

    for (int x = 0; x < h*w*d; ++x){
        o_ptr[x] = floor( ( a+(i_ptr[x]-A)*(b-a) / (B-A) ) + 0.5f );
    }
}

void convertBIP2BSQ(unsigned short *m_lowDetailDataTMP, unsigned short *tmp, int width, int height, int bands){
    unsigned short aux;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(int k=0;k<bands;k++){
                aux = i * width + j;
                tmp[k * height * width + aux] = m_lowDetailDataTMP[aux*bands+k];
            }
        }
    }
}

void readImage(FILE *fp, unsigned char *imageData, int width, int height, int bands, int dataSigned, int endianness, int bip2bsq){
    unsigned short *imageDataTMP;
    imageDataTMP = (unsigned short *)malloc(sizeof(unsigned short)*width*height*bands);

    unsigned short value;
    for(int i=0;i<width*height*bands;i++){
        unsigned char temp1;
        unsigned char temp2;
        fread(&temp1,1,1,fp);
        fread(&temp2,1,1,fp);
        if(endianness==1){
            value = (unsigned short)((temp1 << 8) + temp2);
        }else{
            value = (unsigned short)((temp2 << 8) + temp1);
        }
        if(dataSigned==1){
            imageDataTMP[i] = (short)value;
        }else{
            imageDataTMP[i] = value;
        }
    }

    unsigned short *imageDataAUX;
    imageDataAUX = (unsigned short *)malloc(sizeof(unsigned short)*width*height*bands);
    if(bip2bsq==0){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                for(int k=0;k<bands;k++){
                    imageDataAUX[k * height * width + i*width +j] = imageDataTMP[(i*width+j)*bands + k];
                }
            }
        }
    }else{
        for(int i=0;i<width*height*bands;i++){
            imageDataAUX[i]=imageDataTMP[i];
        }
    }

    imageData[0]=0;
    normalize(imageData,imageDataAUX,0,255,width,height,bands);

    free(imageDataAUX);
    free(imageDataTMP);
}
