/**
 * @file stacker.h
 * @author Christian McKenzie / Tyson Arnold
 * @date 2025-03-07
 * @brief Stacker Class
 * 
 * Reads, averages, adn writes PPM images
 */

#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Pixel{
  int red, green, blue;
}
  
class Stacker {
private:
  std::string magic_number;
  int width, height, max_color;
  std::vector<Pixel> pixels;

public:
  // Constructor
  Stacker();

  /* Reads the PPM image file and accumulates its pixel values
   * @first Shows if its the first image
  */
  bool loadImage(const std::string& filename, bool first);

  /* Averages the pixel values
   * @numImages the total number of images processed
  */
  void averagePixels(int numImages);

  // Saves the final averages image to a PPM file
  bool saveImage(const std::string& filename);
};

#endif
