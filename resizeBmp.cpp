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
    resizeBMP.ReadFromFile(nameFileInput); //"piaf.bmp"

    if(strncmp(option, "p", strlen(option)) == 0) {

        Rescale(resizeBMP, 'p', atoi(sizeImg)); //atoi(argv[1])

    } else if(strncmp(option, "h", strlen(option)) == 0) {

        Rescale(resizeBMP, 'h', atoi(sizeImg));

    } else if(strncmp(option, "w", strlen(option)) == 0){

        Rescale(resizeBMP, 'w', atoi(sizeImg));
    }

    resizeBMP.WriteToFile(nameFileOutput); // "rescale.bmp"
    std::cout << "Resize Bmp Generated !" << std::endl;
}