//
//  unpacker.hpp
//  Texture Atlas Generator
//
//  Created by Indi Kernick on 27/6/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef unpacker_unpacker_hpp
#define unpacker_unpacker_hpp

#include <string>
#include <unordered_map>
#include "image.hpp"

#pragma GCC visibility push(default)

class SpriteNotFound final : public std::range_error {
public:
  SpriteNotFound();
};

class AtlasReadError final : public std::runtime_error {
public:
  explicit AtlasReadError(const char *);
  explicit AtlasReadError(const std::exception &);
};

class Spritesheet {
public:
  //only the factory function can make spritesheets
  friend Spritesheet makeSpritesheet(const std::string &, const std::string &);
  
  static const PosPx2 NO_WHITEPIXEL;
  
  Spritesheet() = default;
  Spritesheet(Spritesheet &&) = default;
  ~Spritesheet() = default;
  
  bool hasWhitepixel() const;
  PosPx2 getWhitepixel() const;
  RectPx getSprite(const std::string &) const;
  
  Image image;
  
private:
  explicit Spritesheet(Image &&);

  std::unordered_map<std::string, RectPx> sprites;
  PosPx2 whitepixel;
};

Spritesheet makeSpritesheet(const std::string &, const std::string &);

#pragma GCC visibility pop

#endif