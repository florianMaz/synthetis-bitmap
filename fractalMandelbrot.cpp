//
// Created by Florian Mazuy on 2019-07-17.
//
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "Headers/EasyBMP.h"
int MAX_ITERATION = 50;
float XMIN = -1.5;
float XMAX = 1.5;
float YMIN = -1.25;
float YMAX = 1.25;
int LARGEUR = 500;
int HAUTEUR = 500;
float cy;
float cx;
int iteratorMax = 255;
BMP Fractal;
RGBApixel color;

int main() {
    Fractal.SetSize(LARGEUR , HAUTEUR);
    for(int y = 1; y<HAUTEUR; y++) {
        for(int x = 1; x<LARGEUR; x++){
            cx = (x * (XMAX - XMIN) / LARGEUR + XMIN);
            cy = (y * (YMIN - YMAX) / HAUTEUR + YMAX);
            float xn = 0;
            float yn = 0;
            int n = 0;
            while((xn * xn + yn * yn) < 4 && n < MAX_ITERATION) {
                float tmp_x = xn;
                float tmp_y = yn;
                xn = tmp_x * tmp_x - tmp_y * tmp_y + cx;
                yn = 2 * tmp_x * tmp_y + cy;
                n = n + 1;
            }
            if(n == MAX_ITERATION) {
                color.Green = 0;
                color.Blue = 0;
                color.Red = 0;
                Fractal.SetPixel(x, y, color);// On colore le pixel en noir -> code RGB : (0,0,0)
            }
            else {
                color.Green = 255;
                color.Blue = 255;
                color.Red = 255;
                Fractal.SetPixel(x, y, color);// On colore le pixel en noir -> code RGB : (255,255,255)
            }
        }
    }

    Fractal.WriteToFile("fractalMandelbrot.bmp");
    return 0;
}
