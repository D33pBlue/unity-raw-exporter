# unity-raw-exporter
This is a simple heightmap exporter for Unity. It takes a PNG image and converts it in a raw file Unity can read.

## How to build
*Note: Pre-built files for linux and windows are already included.*

First you need to download or clone this repository. Then:
- *for linux* you can build with g++:
```
g++ -o heightmapExporter heightmapExporter.cpp
```

- *for windows* you can use Visual Studio or MinGW. To built the windows executable under linux you can use g++-mingw-w64:
```
sudo apt install g++-mingw-w64
i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ heightmapExporter.cpp -o heightmapExporter.exe
```

## How to use
You can simply run in your shell:
```
./heightmapExporter "path/to/imageToConvert.png"
```
and the heightmap is stored in "terr.raw" file.

In windows you can drag and drop the PNG file onto the executable.

## Dependencies
The picopng library is used in order to load the PNG images (see https://lodev.org/lodepng/picopng.cpp ).
