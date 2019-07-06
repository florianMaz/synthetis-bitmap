#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "Headers/EasyBMP.h"

double startTime;
double endTime;
int col;
BMP BlackWhiteScale;
BMP OutputBlackWhiteScale;

BMP NegaScale;
BMP OutputNegaScale;
RGBApixel colorNega;
RGBApixel outputColorNega;

int picWidth;
int picHeight;
int RED;
int GREEN;
int BLUE;
int width;
int height;

void bmpToNegative(){
    NegaScale.ReadFromFile("piaf.bmp");
    picWidth = NegaScale.TellWidth();
    picHeight = NegaScale.TellHeight();
    NegaScale.SetSize(NegaScale.TellWidth() , NegaScale.TellHeight());
    NegaScale.SetBitDepth(1);
    #pragma omp parallel for private(width, height, RED, BLUE, GREEN)
    for (width = 1; width < picWidth-1; ++width) {
        for (height = 1; height < picHeight-1; ++height) {
            colorNega = NegaScale.GetPixel(width,height);

            outputColorNega.Blue = 255 - colorNega.Blue/2;
            outputColorNega.Red = 255 - colorNega.Red/2;
            outputColorNega.Green = 255 - colorNega.Green/2;
            NegaScale.SetPixel(width, height, outputColorNega);
            if(width<10 && height<10){
                printf("red : %d\n",  colorNega.Red);
                printf("Blue : %d\n",  colorNega.Blue);
                printf("green : %d\n",  colorNega.Green);
            }
        }
    }

    NegaScale.WriteToFile("piafnegative.bmp");
}

void bmpToBlackWhite(){
    BlackWhiteScale.ReadFromFile("piaf.bmp");
    picWidth = BlackWhiteScale.TellWidth();
    picHeight = BlackWhiteScale.TellHeight();
    OutputBlackWhiteScale.SetSize(BlackWhiteScale.TellWidth() , BlackWhiteScale.TellHeight());
    OutputBlackWhiteScale.SetBitDepth(1);
    startTime = omp_get_wtime();
    #pragma omp parallel for private(col, width, height, RED, BLUE, GREEN)
    for (width = 1; width < picWidth-1; ++width) {
        for (height = 1; height < picHeight-1; ++height) {
            col = (BlackWhiteScale(width,height)->Blue + BlackWhiteScale(width,height)->Green +10* BlackWhiteScale(width,height)->Red)/12;
            if (col > 127) {
                OutputBlackWhiteScale(width,height)->Red = 255;
                OutputBlackWhiteScale(width,height)->Blue = 255;
                OutputBlackWhiteScale(width,height)->Green = 255;
            } else {
                OutputBlackWhiteScale(width,height)->Red = 0;
                OutputBlackWhiteScale(width,height)->Blue = 0;
                OutputBlackWhiteScale(width,height)->Green = 0;
            }
        }
    }
    endTime = omp_get_wtime();
    printf("Time for loop : %f seconds\n", (endTime-startTime));

    OutputBlackWhiteScale.WriteToFile("piafblackwhite.bmp");
}

int main(int argc, char const *argv[]) {

    int choix;

    printf("1.Black & White Bmp \n2.Negative Bmp\n");
    printf("Choice: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            bmpToBlackWhite();
            break;
        case 2:
            bmpToNegative();
            break;
        default:
            printf("Error choice\n");
            break;

    }
    printf("\n");

    return 0; 
}


