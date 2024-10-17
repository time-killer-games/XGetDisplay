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

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  int displayWidth = display_get_width();
  int displayHeight = display_get_height();
  int displayX = display_get_x();
  int displayY = display_get_y();
  if (argc == 1) {
    printf("Primary Monitor [Width*Height+X+Y]: %d*%d+%d+%d\n", displayWidth, displayHeight, displayX, displayY);
  } else if (argc == 2) { 
    if (strcmp(argv[1], "-x") == 0 || strcmp(argv[1], "--x") == 0) {
      printf("%d\n", displayX);
    } else if (strcmp(argv[1], "-y") == 0 || strcmp(argv[1], "--y") == 0) {
      printf("%d\n", displayY);
    } else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--w") == 0 || strcmp(argv[1], "-width") == 0 || strcmp(argv[1], "--width") == 0) {
      printf("%d\n", displayWidth);
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "-height") == 0 || strcmp(argv[1], "--height") == 0) {
      printf("%d\n", displayHeight);
    }
  }
  return 0;
}
