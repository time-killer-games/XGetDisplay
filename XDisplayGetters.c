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

#include <limits.h>

#include "XDisplayGetters.h"

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#include <X11/extensions/Xinerama.h>

static int displayX = INT_MIN;
static int displayY = INT_MIN;
static int displayWidth = INT_MIN;
static int displayHeight = INT_MIN;

static void display_get_position(Bool i, int *result) {
  Display *display = XOpenDisplay(NULL);
  *result = 0; Rotation original_rotation; 
  Window root = XDefaultRootWindow(display);
  XRRScreenConfiguration *conf = XRRGetScreenInfo(display, root);
  SizeID original_size_id = XRRConfigCurrentConfiguration(conf, &original_rotation);
  if (XineramaIsActive(display)) {
    int m = 0; XineramaScreenInfo *xrrp = XineramaQueryScreens(display, &m);
    if (!i) *result = xrrp[original_size_id].x_org;
    else if (i) *result = xrrp[original_size_id].y_org;
    XFree(xrrp);
  }
  XCloseDisplay(display);
}

static void display_get_size(Bool i, int *result) {
  Display *display = XOpenDisplay(NULL);
  *result = 0; int num_sizes; Rotation original_rotation; 
  Window root = XDefaultRootWindow(display);
  int screen = XDefaultScreen(display);
  XRRScreenConfiguration *conf = XRRGetScreenInfo(display, root);
  SizeID original_size_id = XRRConfigCurrentConfiguration(conf, &original_rotation);
  if (XineramaIsActive(display)) {
    XRRScreenSize *xrrs = XRRSizes(display, screen, &num_sizes);
    if (!i) *result = xrrs[original_size_id].width;
    else if (i) *result = xrrs[original_size_id].height;
  } else if (!i) *result = XDisplayWidth(display, screen);
  else if (i) *result = XDisplayHeight(display, screen);
  XCloseDisplay(display);
}

int display_get_x() {
  if (displayX != INT_MIN)
    return displayX;
  display_get_position(False, &displayX);
  return displayX;
}

int display_get_y() { 
  if (displayY != INT_MIN)
    return displayY;
  display_get_position(True, &displayY);
  return displayY;
}

int display_get_width() {
  if (displayWidth != INT_MIN) 
    return displayWidth;
  display_get_size(False, &displayWidth);
  return displayWidth;
}

int display_get_height() {
  if (displayHeight != INT_MIN)
    return displayHeight;
  display_get_size(True, &displayHeight);
  return displayHeight;
}
