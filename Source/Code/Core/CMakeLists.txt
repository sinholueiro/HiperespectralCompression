cmake_minimum_required(VERSION 3.7)
project(ImageCompressionMerge)

find_package(OpenJPEG REQUIRED)
find_package(TIFF REQUIRED)
find_package(PNG REQUIRED)
include_directories(${OPENJPEG_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

file(GLOB lib "lib/*.h" "lib/*.cpp")
file(GLOB lib3D "lib3D/*.h" "lib3D/*.cpp")
set(SOURCE_FILES main.cpp utils2D.h utils3D.h ${lib} ${lib3D} lib/convert.cpp lib3D/convert.cpp bip2bsq.cpp callback.cpp callback.h compression2D.cpp compression3D.cpp decode.cpp statistics.cpp statistics3D.cpp)

add_executable(ImageCompressionMerge ${SOURCE_FILES})
target_link_libraries(ImageCompressionMerge ${OPENJPEG_LIBRARIES} ${PNG_LIBRARY} ${TIFF_LIBRARY})