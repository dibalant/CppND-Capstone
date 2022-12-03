#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "SDL.h"

class Character
{
public:
    enum class Direction
    {
        kUp,
        kDown,
        kLeft,
        kRight
    };

    Character(int gridWidth, int gridHeight, std::vector<SDL_Keycode> keys)
        : grid_width(gridWidth),
          grid_height(gridHeight),
          key_up(keys[0]),
          key_down(keys[1]),
          key_left(keys[2]),
          key_right(keys[3]) {}

    Character(int gridWidth, int gridHeight)
        : grid_width(gridWidth),
          grid_height(gridHeight),
          key_up(SDLK_UP),
          key_down(SDLK_DOWN),
          key_left(SDLK_LEFT),
          key_right(SDLK_RIGHT) {}

    virtual ~Character() = default;

    virtual void Update() {}

    virtual void PointEarned() {}

    int GetScore() const
    {
        return score;
    }

    Direction direction = Direction::kUp;

    float speed = 0.1f;
    int size = 1;
    float head_x = 0;
    float head_y = 0;

    SDL_Keycode key_up;
    SDL_Keycode key_down;
    SDL_Keycode key_right;
    SDL_Keycode key_left;

protected:
    int grid_width;
    int grid_height;
    int score{0};
    const float speed_increase_interval = 0.02;
};
#endif