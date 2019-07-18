cmake_minimum_required(VERSION 3.12)
project(synthetis_bitmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(synthetis_bitmap
        Headers/EasyBMP.h
        Headers/EasyBMP_BMP.h
        Headers/EasyBMP_DataStructures.h
        Headers/EasyBMP_VariousBMPutilities.h
        sample/EasyBMPsample.cpp
        EasyBMP.cpp
        fractalJulia.cpp
        main.cpp
        resizeBmp.cpp)
