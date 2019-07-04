#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "EasyBMP.h"

int main(int argc, char const *argv[]) {
    double startTime;
    double endTime;
    BMP Greyscale;  
    Greyscale.ReadFromFile("piaf.bmp");  
    BMP OutputGreyscale;  
    int picWidth = Greyscale.TellWidth();  
    int picHeight = Greyscale.TellHeight();  
    OutputGreyscale.SetSize(Greyscale.TellWidth() , Greyscale.TellHeight());  
    OutputGreyscale.SetBitDepth(1);
    startTime = omp_get_wtime();
    #pragma omp parallel for private(col)
    for (int i = 1; i < picWidth-1; ++i) {
        for (int j = 1; j < picHeight-1; ++j) {   
                    int col = (Greyscale(i, j)->Blue + Greyscale(i,j)->Green +10* Greyscale(i,j)->Red)/12;   
                    if (col > 127) {  
                        OutputGreyscale(i,j)->Red = 255;
                        OutputGreyscale(i,j)->Blue = 255;
                        OutputGreyscale(i,j)->Green = 255; 
                    } else {
                        OutputGreyscale(i,j)->Red = 0;
                        OutputGreyscale(i,j)->Blue = 0;
                        OutputGreyscale(i,j)->Green = 0;      
                    }    
        }
    }
    end = omp_get_wtime();
    printf("Time for loop : %f seconds\n", (endTime-startTime));

    OutputGrayscale.WriteToFile("piafgreyscale.bmp");  
    return 0; 
}
