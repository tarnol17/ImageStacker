/**
 * @file stacker.cpp
 * @author Christian McKenzie / Tyson Arnold
 * @date 2025-03-07
 * @brief Implementation file for stacker class
 * 
 * Read, stack, average, and save PPM images.
 */

#include "stacker.h"
#include <iostream>
#include <fstream>
#include <sstream>

//Constructor
Stacker::Stacker(){
  magic_number = "P3";
  width = 0;
  height = 0;
  max_color = 255;
}

//Reads the PPM image file and accumulates its pixel values
bool Stacker::loadImage(const std::string &filename, bool first){
  std::ifstream file(filename);
  if(!file){
    std::cerr << "Error: Cannot Open " << filename << "\n";
    return false;
  }

  std::string line;
  std::getline(file, magic_number);
  file >> width >> height >> max_color;

  std::vector<Pixel> tempPixels;
  int r, g, b;
  while(file >> r >> g >> b) //Read pixel values
    tempPixels.push_back({r, g, b});

  if(first) {
    pixels = tempPixels; //Initialize on first image
  } else {
    for(size_t i = 0; i < pixels.size(); i++){
      pixels[i].red += tempPixels[i].red;
      pixels[i].green += tempPixels[i].green;
      pixels[i].blue += tempPixels[i].blue;
    }
  }
  return true;
}

//Averages the pixel values
void Stacker::averagePixels(int numImages){
  for(size_t i = 0; i < pixels.size(); i++){
    pixels[i].red /= numImages;
    pixels[i].green /= numImages;
    pixels[i].blue /= numImages;
  }
}

//Saves the final averages image to a PPM file
bool Stacker::saveImage(const std::string& filename){
  std::ofstream file(filename);
  if(!file){
    std::cerr << "Error: Cannot Open " << filename << "\n";
    return false;
  }

  //Header
  file << magic_number << "\n" << width << " " << height << "\n" << max_color << "\n";

  //Pixels
  for(size_t i = 0; i < pixels.size(); i++){
    file << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << " ";
    if((i + 1) % width == 0) file << "\n"; //New line after each row
  }

return true;
}


