#!/bin/bash

mkdir Build
cd Build
mkdir build
cd build
cmake ../../Code/Core/
make

cd ..
qmake -o Makefile ../Code/UI/QTCompression.pro
make

mv QTCompression HyperspectralCompression
rm *.h *.o *.cpp Makefile
cd Build

