#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include "character.h"
#include <vector>

class Food : public Character
{
public:
  Food(int grid_width, int grid_height) : Character(grid_width, grid_height) {}

  Food(int grid_width, int grid_height, std::vector<SDL_Keycode> key_mapping ) : Character(grid_width, grid_height, key_mapping) {}
};
#endif