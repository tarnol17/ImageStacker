#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Stacker {
private:
    std::string magic_number;
    int width, height, max_color;
    std::vector<Pixel> pixels;
    struct Pixel {
        int red, green, blue;
    };

public:
    Stacker();
    bool loadImage(const std::string& filename);
    void writeOutput(const std::string& outputFilename) const;
};

#endif
