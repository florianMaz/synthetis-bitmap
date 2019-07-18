//
// Created by laureen martina on 04/07/2019.
//

#include <iostream>
#include "Headers/EasyBMP.h"
using namespace std;


int main(int argc, char* argv[]) {
    char sizeImg [2049];
    char nameFileInput[2049];
    char nameFileOutput[2049];
    char option[2];

    strcpy(sizeImg, argv[1]);
    strcpy(option, argv[2]);
    strcpy(nameFileInput, argv[3]);
    strcpy(nameFileOutput, argv[4]);

    BMP resizeBMP;
    resizeBMP.ReadFromFile(nameFileInput); //"image.bmp"

    int imageWidth = resizeBMP.TellWidth();
    int imageHeight = resizeBMP.TellHeight();

    if(strncmp(option, "p", strlen(option)) == 0) {

        Rescale(resizeBMP, 'p', atoi(sizeImg));

    } else if(strncmp(option, "h", strlen(option)) == 0) {

        Rescale(resizeBMP, 'h', atoi(sizeImg));

    } else if(strncmp(option, "w", strlen(option)) == 0){

        Rescale(resizeBMP, 'w', atoi(sizeImg));
    }

    resizeBMP.WriteToFile(nameFileOutput); // "rescale.bmp"
    printf("Dimensions Image: %d x %d\n", imageWidth, imageHeight);

    int imageWidthFinal = resizeBMP.TellWidth();
    int imageHeightFinal = resizeBMP.TellHeight();

    printf("Rescale Image: %d x %d\n", imageWidthFinal, imageHeightFinal);
    printf("Resize Bmp Generated !");
}