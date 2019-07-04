//
// Created by laureen martina on 04/07/2019.
//

#include <iostream>
#include "EasyBMP.h"
using namespace std;


int main(int argc, char* argv[]) {
    char sizeImg [2049];
    //char *option;

    strcpy(sizeImg, argv[1]);
    //strcpy(option, argv[2]);


    BMP resizeBMP;
    resizeBMP.ReadFromFile("piaf.bmp");

    Rescale(resizeBMP, 'p', atoi(sizeImg)); //atoi(argv[1]) //*option

    resizeBMP.WriteToFile("rescale.bmp");
    std::cout << "Resize Bmp Generated !" << std::endl;
}