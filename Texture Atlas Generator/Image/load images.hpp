//
//  load images.hpp
//  Texture Atlas Generator
//
//  Created by Indi Kernick on 22/4/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef image_load_images_hpp
#define image_load_images_hpp

#include <string>
#include "image.hpp"
#include <experimental/string_view>

#ifdef BUILDING_PACKER

#include <vector>

class NoLoadedImagesError final : public std::runtime_error {
public:
  NoLoadedImagesError();
};

std::vector<Image> loadImages(const std::vector<std::string> &);

#endif

class ImageLoadError final : public std::runtime_error {
public:
  ImageLoadError(std::experimental::string_view, std::experimental::string_view);
};

#ifdef BUILDING_PACKER
Image loadImage(std::experimental::string_view);
#else
Unpack::Image loadImage(std::experimental::string_view);
#endif

#endif
