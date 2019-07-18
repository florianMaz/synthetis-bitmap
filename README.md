# synthetis-bitmap

## Transform Image BMP to Black&White Image or Negative Image

```
g++ -Xpreprocessor -fopenmp -lomp -o synthesis main.cpp EasyBMP.cpp && ./synthesis
./synthesis
```

## rescale Image BMP

```
g++ -Xpreprocessor -fopenmp -lomp -o rescale resizeBmp.cpp EasyBMP.cpp
./rescale 50 p fileSource fileDestination
```

## Fractal : ensemble de Julia
```
g++ -Xpreprocessor -fopenmp -lomp -o fractal fractalJulia.cpp EasyBMP.cpp
./fractal
```