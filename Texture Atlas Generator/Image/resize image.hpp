//
//  resize image.hpp
//  Texture Atlas Generator
//
//  Created by Indi Kernick on 22/6/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef image_resize_image_hpp
#define image_resize_image_hpp

#include "image.hpp"

//keep this in sync with stb_image_resize.c
constexpr size_t RESIZE_TEMP_SIZE = 32 * 1024 * 1024;//32MB

///Resizes an sRGB alpha image
Image resizeSRGB(const Image &, SizePx2);

#endif
