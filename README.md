# README:: PPM Image Stacker
## Overview
The program makes PPM images by stacking multiple images together and averaging their pixel values to create and output a final image.

## Design Decisions
- Pixels are stored in a vector, where Pixel is a structure contatining red, green, and blue.
- The first image initializes the array, then subsequent images have their pixel values added to the existing values.

## How to Run the Porgram
1. Run make
2. Run the program using ./Stacker
3. It will ask for the image to stack, the names of the images are "orion, cone_nebula, n44f, wfc3_uvis"
4. Then open the output file with emacs and you should be able to view it.
