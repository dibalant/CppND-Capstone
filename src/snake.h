#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "character.h"

class Snake : public Character
{
public:
  Snake(int grid_width, int grid_height) : Character(grid_width, grid_height)
  {
    head_x = grid_width / 2;
    head_y = grid_height / 2;
  }

  Snake(int grid_width, int grid_height, std::vector<SDL_Keycode> key_mapping) : Character(grid_width, grid_height, key_mapping)
  {
    head_x = grid_width / 2;
    head_y = grid_height / 2;
  }

  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y);

  std::vector<SDL_Point> body;

  bool alive = true;

private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
};

#endif