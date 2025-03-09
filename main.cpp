/**
 * @file main.cpp
 * @author Christian McKenzie / Tyson Arnold
 * @date 2025-03-07
 * @brief Set the PPM images
 * 
 */

#include "stacker.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    //Variables
    std::string baseName;
    int numImages;

    //User Input
    std::cout << "Please enter the image you wish to stack: ";
    std::cin >> baseName;
    std::cout << "Please enter the number of images: ";
    std::cin >> numImages;

    //Stacker Object
    Stacker stacker;

    //Loop through images
    for(int i = 1; i <= numImages; i++){
        std::string filename = baseName + "/" + baseName + "_" + (i < 10 ? "00" : i < 100 ? "0" : "") + std::to_string(i) + ".ppm";
        
        if (!stacker.loadImage(filename, i == 1)){
            return 1;
        }
    }

    //Average the images
    stacker.averagePixels(numImages);
    if(!stacker.saveImage(baseName +  ".ppm")){
        return 1;
    }

    std::cout << "Stacking Complete. Output saved to " << baseName << ".ppm\n";
    return 0;
}