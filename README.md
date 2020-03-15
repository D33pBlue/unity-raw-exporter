# unity-raw-exporter
This is a simple heightmap exporter for Unity. It takes a PNG image and converts it in a raw file Unity can read.

## How to build
First you need to download or clone this repository. Then:
- *for linux* you can build with g++:
```
g++ -o heightmapExporter heightmapExporter.cpp
```
- *for windows* you can use Visual Studio or MinGW

## How to use
You can simply run in your shell:
```
./heightmapExporter "path/to/imageToConvert.png"
```
and the heightmap is stored in "terr.raw" file.

## Dependencies
The picopng library is used in order to load the PNG images. You can find this library at https://lodev.org/lodepng/picopng.cpp
