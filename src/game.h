#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <string>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  const std::string key_mapping_file{"../config/keymappings"};

private:
  Snake snake;
  Food food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
  std::vector<SDL_Keycode> ReadKeys(std::string character);
};

#endif