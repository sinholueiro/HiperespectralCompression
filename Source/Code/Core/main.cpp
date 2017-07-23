#include <cstdlib>
#include <time.h>

#include "utils2D.h"
#include "utils3D.h"

int main(int argc, char *argv[]) {
    char *input=argv[1];
    char *output=argv[2];
    int w=strtol(argv[3],NULL,10);
    int h=strtol(argv[4],NULL,10);
    int b=strtol(argv[5],NULL,10);
    int d=strtol(argv[6],NULL,10);
    int s=strtol(argv[7],NULL,10);

    int mode = strtol(argv[8],NULL,10);

    int endian = strtol(argv[9],NULL,10); //1 is littleEndian
    int bsq = strtol(argv[10],NULL,10); //1 is BSQ

    switch(mode){
        case 1:
            compression2D(input,output,w,h,b,d,s,endian,bsq,1);
            break;
        case 2:
            compression2D(input,output,w,h,b,d,s,endian,bsq,0);
            break;
        case 3:
            compression3D(input,output,w,h,b,d,s,endian,bsq);
            break;
    }

    return 0;
}