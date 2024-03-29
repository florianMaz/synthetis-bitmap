/*
 * Dessiner un ensemble de Julia dans le plan x[-1.5 +1.5], y[-1.5 +1.5]
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "Headers/EasyBMP.h"
#include <math.h>

#define a -0.0300//-0.0849
#define b 0.7200//0.8721
#define xMaxRepere 1.5 //x[-1.5 +1.5]
#define yMaxRepere 1.5 //y[-1.5 +1.5]

RGBApixel color;
BMP Fractal;
double startTime;
double endTime;

int main(int argc, char const *argv[]) {
    printf("Fractal Julia Generated !\n");

    int widthImg = 1000;
    int heightImg = 1000;
    double C;

    int x, y, etape;
    double x2, y2, new_x, new_y;

    Fractal.SetSize(widthImg , heightImg);

    startTime = omp_get_wtime();

    #pragma omp parallel for private(x, y, x2, y2, etape, new_x, new_y, C, color)
    for(x = 0; x < widthImg; x++) {
        for(y = 0; y < heightImg; y++) {

            x2 = x * 0.003-xMaxRepere;
            y2 = y * 0.003-yMaxRepere;

            for(etape = 0; etape < 255; etape++) {

                //Z0 = x + i.y    initiale
                //C = |Z| = sqr(x*x + y*y)
                //C = x*x + y*y;

                //etape de calcul
                // init new_x, new_y;

                new_x = x2*x2 - y2*y2 + a;
                new_y = 2*(x2 * y2) + b;

                //1ème étape      i (nb imaginaire) dont le carré vaut -1

                //ZCarre = x*x - y*y + 2*(x * y);

                //2è étape
                //Z1 = ZCarre + C
                //Z1 = x*x - y*y + 2*(x * y) + b;

                //3ème étape
                //|Z| => norme imaginaire sqrt(a^2 + b^2)
                C = (new_x * new_x) + (new_y * new_y);

                // test si on a fini ou color pixel
                if(C > 4 || etape <= 200) {
                    color.Red = static_cast<ebmpBYTE>(etape + 100);
                    color.Blue = static_cast<ebmpBYTE>(etape + 30);
                    color.Green = static_cast<ebmpBYTE>(etape);
                    Fractal.SetPixel(x, y, color);
                }

                if (C > 4 || etape >= 255) {
                    //alors le pixel vaut la color courante
                    color.Red = static_cast<ebmpBYTE>(etape);
                    color.Blue = static_cast<ebmpBYTE>(etape);
                    color.Green = static_cast<ebmpBYTE>(etape);
                    Fractal.SetPixel(x, y, color);
                    break;
                }

                x2 = new_x;
                y2 = new_y;
            }
        }
    }

    endTime = omp_get_wtime();

    printf("Time for loop : %f seconds\n", (endTime-startTime));

    Fractal.WriteToFile("fractal.bmp");

    return 0;
}


