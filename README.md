# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## Capstone Project Changes
For my capstone project, I have extended the simple Snake game into a head-to-head, two player challenge.
The piece of food is now a playable character. The goal of the game is now for the snake to eat the food and for the food to escape the snake.
The snake is awarded a point for each time it successfully eats the food. The food is awarded a point for every 10 seconds it avaids the snake. Each character will speed up as they collect more points.
The game still ends when the snake collides with itself or when the user manually quits.

## Rubric Points Met
* The project reads data from a file and process the data, or the program writes data to a file.
  * Key bindings for each character can be set in the file config/keymappings. The file is read and parsed on start up of the game and assigns as many or as few keys are specified by the config file.
  * By default both characters will use the arrow keys for movement.
  * Future work: 
    * Checks to be added to throw an error if both characters have the same key set
    * A method to change the key bindings without needing to restart the game
    * Error handling for if an invalid key is set or bad file input
* The project accepts user input and processes the input.
  * Controller.cpp was changed in such a way that it can accept and process user input from a dynamic set of keys, as long as they are assinged to one of the characters on start up (see point 1).
* Classes follow an appropriate inheritance hierarchy.
  * Since there are now two types of characters, the generic character class was introduced to encapsulate the generic character attributes and functions.
  * Snake and Food classes extend the Character class to share the common functionaility of knowing the direction they are headed, their current head coordinate, speed, and key bindings. 
* Overloaded functions allow the same function to operate on different parameters.
  * The Character class has two constructors. One for if the default keys are to be set and one for if custom keys are set.
* Derived class functions override virtual base class functions.
  * The Character class contains the virtual functions Update() and PointEarned() for each of its child classes to implement. 
  * For Update(), the Snake class needs to redraws both the head and the body of the snake when the direction changes, while the Food only needs to update the head location.
  * For PointEarned(), the Snake needs to grow its body, increase its points, and increase its speed. The food only needs to increase its points and its speed.
* Class constructors utilize member initialization lists.
  * The Character, Snake, and Food classes each utilize member initialization lists in their constructors where appropriate.
* Classes encapsulate behavior.
  * Each character now holds its own score counter instead of the Game class handling this counter.
  * The Game class collects the score from each player character to display at the top of the game window and print to the console at the end of the game.