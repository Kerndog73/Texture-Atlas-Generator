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
  ImageLoadError(const std::string &, const std::string &);
};

Image loadImage(const std::string &);

#endif
