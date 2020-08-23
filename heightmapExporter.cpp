// Copyright (c) 2020 d33pblue
/* This program can convert a PNG image into a raw heightmap for Unity.
* It considers only the r channel in the png (0-255) as height.
* The library picopng is used in order to load the PNG image.
* see: https://lodev.org/lodepng/picopng.cpp
*/
#include <iostream>
#include <fstream>
#include <string>
#include "dependencies/picopng.h"
using namespace std;


int main(int argc, char const *argv[]) {
  string path = argv[1];
  cout<<"Converting "<<path<<endl;
  std::vector<unsigned char> buffer,out_image;
  loadFile(buffer, path);
  unsigned long image_width,image_height;
  if(decodePNG(out_image,image_width,image_height,
      &buffer[0], (unsigned long)buffer.size())){
    cout<<"Error!"<<endl;
    return 1;
  }
  FILE* pFile = fopen ("terr.raw", "wb");
  for(int i=0;i<image_width;i++){
    for(int j=0;j<image_height;j++){
      int16_t d = (int16_t)out_image[(i*image_height+j)*4];
      d = d*100;
      fwrite(&d,sizeof(int16_t),1,pFile);
    }
  }
  fclose(pFile);
  cout<<"ok!"<<endl;
  return 0;
}
