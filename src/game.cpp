#include "game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "SDL.h"

using std::string;
using std::vector;

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      food(grid_width, grid_height, ReadKeys("food")),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, food);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.head_x = x;
      food.head_y = y;
      return;
    }
  }
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();
  food.Update();

  int new_snake_x = static_cast<int>(snake.head_x);
  int new_snake_y = static_cast<int>(snake.head_y);

  int new_food_x = static_cast<int>(food.head_x);
  int new_food_y = static_cast<int>(food.head_y);

  // Check if snake caught the food
  if (new_snake_x == new_food_x && new_snake_y == new_food_y)
  {
    score++;
    //PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

vector<SDL_Keycode> Game::ReadKeys(string character)
{
  vector<SDL_Keycode> key_mapping{SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT};
  string line;
  string charac, direction, key;

  std::ifstream filestream(key_mapping_file);
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      while (linestream >> charac >> direction >> key)
      {
        if (charac == character)
        {
          if (direction == "up")
          {
            key_mapping[0] = SDL_GetKeyFromName(key.c_str());
          }
          else if (direction == "down")
          {

            key_mapping[1] = SDL_GetKeyFromName(key.c_str());
          }
          else if (direction == "left")
          {

            key_mapping[2] = SDL_GetKeyFromName(key.c_str());
          }
          else if (direction == "right")
          {

            key_mapping[3] = SDL_GetKeyFromName(key.c_str());
          }
        }
      }
    }
  }
  return key_mapping;
}