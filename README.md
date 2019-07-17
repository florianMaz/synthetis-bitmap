# synthetis-bitmap

g++ -Xpreprocessor -fopenmp -lomp -o synthesis main.cpp EasyBMP.cpp && ./synthesis

# rescale BMP
g++ -Xpreprocessor -fopenmp -lomp -o rescale resizeBmp.cpp EasyBMP.cpp
./rescale 50 p fileSource fileDestination