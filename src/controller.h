#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "character.h"
#include "snake.h"
#include "food.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Food &food) const;

 private:
  void ChangeDirection(Character &character, Character::Direction input,
                       Character::Direction opposite) const;
};

#endif