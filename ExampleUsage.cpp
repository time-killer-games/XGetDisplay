/*

 MIT License
 
 Copyright © 2024 Samuel Venable
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
*/

#include "XDisplayGetters.h"

#include <iostream>
#include <string>

using std::string;
using std::to_string;

int main(int argc, char **argv) {
  string displayX      = to_string(display_get_x());
  string displayY      = to_string(display_get_y());
  string displayWidth  = to_string(display_get_width());
  string displayHeight = to_string(display_get_height());
  if (argc == 1) {
    std::cout << "Primary Monitor [Width*Height+X+Y]: " + displayWidth + "*" + displayHeight + "+" + displayX + "+" + displayY << std::endl;
  } else if (argc == 2) {
    string arg = argv[1];
    if (arg == "-x" || arg == "--x") {
      std::cout << displayX << std::endl;
    } else if (arg == "-y" || arg == "--y") {
      std::cout << displayY << std::endl;
    } else if (arg == "-w" || arg == "--w" || arg == "-width" || arg == "--width") {
      std::cout << displayWidth << std::endl;
    } else if (arg == "-h" || arg == "--h" || arg == "-height" || arg == "--height") {
      std::cout << displayHeight << std::endl;
    }
  }
  return 0;
}
