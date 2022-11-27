#include "controller.h"

#include <iostream>

#include "SDL.h"
#include "character.h"
#include "snake.h"
#include "food.h"

void Controller::ChangeDirection(Character &character, Character::Direction input,
                                 Character::Direction opposite) const
{
    if (character.direction != opposite || character.size == 1)
        character.direction = input;
    return;
}

void Controller::HandleInput(bool &running, Snake &snake, Food &food) const
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == snake.key_up)
            {
                ChangeDirection(snake, Character::Direction::kUp,
                                Character::Direction::kDown);
            }
            else if (e.key.keysym.sym == snake.key_down)
            {
                ChangeDirection(snake, Character::Direction::kDown,
                                Character::Direction::kUp);
            }
            else if (e.key.keysym.sym == snake.key_left)
            {
                ChangeDirection(snake, Character::Direction::kLeft,
                                Character::Direction::kRight);
            }
            else if (e.key.keysym.sym == snake.key_right)
            {
                ChangeDirection(snake, Character::Direction::kRight,
                                Character::Direction::kLeft);
            }

            if (e.key.keysym.sym == food.key_up)
            {
                ChangeDirection(food, Character::Direction::kUp,
                                Character::Direction::kDown);
            }
            else if (e.key.keysym.sym == food.key_down)
            {
                ChangeDirection(food, Character::Direction::kDown,
                                Character::Direction::kUp);
            }
            else if (e.key.keysym.sym == food.key_left)
            {
                ChangeDirection(food, Character::Direction::kLeft,
                                Character::Direction::kRight);
            }
            else if (e.key.keysym.sym == food.key_right)
            {
                ChangeDirection(food, Character::Direction::kRight,
                                Character::Direction::kLeft);
            }
        }
    }
}