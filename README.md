# Capstone Porject - Udacity C++ Nanodegree: Snake Game

This project was built upon a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

In this project, a C++ Snake game is extended, following the principles taught throughout this Nanodegree Program using a wide range of C++ features.

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

## Class Structure 


### CppND-Capstone-Snake-Game

* [.vscode/](./.vscode)
  * [c_cpp_properties.json](./.vscode/c_cpp_properties.json)
  * [settings.json](./.vscode/settings.json)
* [cmake/](./cmake) 
  * [FindSDL2_image.cmake](./cmake/FindSDL2_image.cmake)
* [src/](./src)
  * [ThreadObject.cpp](./src/ThreadObject.cpp)
  * [ThreadObject.h](./src/ThreadObject.h)
  * [controller.cpp](./src/controller.cpp)
  * [controller.h](./src/controller.h)
  * [game.cpp](./src/game.cpp)
  * [game.h](./src/game.h)
  * [main.cpp](./src/main.cpp)
  * [renderer.cpp](./src/renderer.cpp)
  * [renderer.h](./src/renderer.h)
  * [snake.cpp](./src/snake.cpp)
  * [snake.h](./src/snake.h)
* [.gitignore](./.gitignore)
* [CMakeLists.txt](./CMakeLists.txt) (updated to include multithreading and new classes)
* [CODEOWNERS](./CODEOWNERS)
* [LICENSE.md](./LICENSE.md)
* [README.md](./README.md)
* [snake_game.gif](./snake_game.gif)



## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
