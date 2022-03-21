# Capstone Project - Udacity C++ Nanodegree: Snake Game

This project was built upon a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

In this project, a C++ Snake game is extended, following the principles taught throughout this Nanodegree Program using a wide range of C++ features.
My contribution:
* Enhanced the classes with OOP in mind.
* Better memory managment by incorporating Smart Pointers & making use of references.
* Incoporated Multithreading and Mutex locks
* Code Documentation

<img src="snake_game.gif"/>

## Table of contents
* [Dependencies for Running Locally](#dependencies-for-running-locally)
* [Basic Build Instructions](#basic-build-instructions)
* [Project Structure](#project-structure)
* [Udacity Rubric Points](#udacity-rubric-points)

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

## Project Structure 


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

## Udacity Rubric Points

### Loops,Functions, I/O
|                    | Criteria                                                                           | Meets Specifications                                                                                           | Notes              |
|--------------------|------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|--------------------|
| :heavy_check_mark: | The project demonstrates an understanding of C++ functions and control structures. | A variety of control structures are used in the project. The project code is clearly organized into functions. | Throughout project |
| :heavy_check_mark: | The project accepts user input and processes the input.                            | The project accepts input from a user as part of the necessary operation of the program.                       | `Controller.cpp`   |

### Object Oriented Programming
|                    | Criteria                                                       | Meets Specifications                                                                                                                                                                         | Notes                                                                                                                                                                                                                      |
|--------------------|----------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| :heavy_check_mark: | The project uses Object Oriented Programming techniques.       | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.                                                                       | Throughout project                                                                                                                                                                                                         |
| :heavy_check_mark: | Classes use appropriate access specifiers for class members.   | All class data members are explicitly specified as public, protected, or private.                                                                                                            | Throughout project                                                                                                                                                                                                         |
| :heavy_check_mark: | Classes abstract implementation details from their interfaces. | All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.      | Function names selected to describe behavior. Documentation added for all code; old & new.                                                                                                                                 |
| :heavy_check_mark: | Classes encapsulate behavior.                                  | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.                        | Throughout project                                                                                                                                                                                                         |
| :heavy_check_mark: | Classes follow an appropriate inheritance hierarchy.           | Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. | New class `ThreadObject` is an abstract class that is inherited by `Controller` & `Game`. Contains common functionality including a pure virtual function. Override is explicitly specified in `Controller.h` & `Game.h`.  |
| :heavy_check_mark: | Derived class functions override virtual base class functions. | One member function in an inherited class overrides a virtual base class member function.                                                                                                    | `Controller` & `Game` override pure virtual function `runThread()`.                                                                                                                                                        |

### Memory Management

|                    | Criteria                                                      | Meets Specifications                                                                                                           | Notes                                                                                                                                 |
|--------------------|---------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| :heavy_check_mark: | The project makes use of references in function declarations. | At least two variables are defined as references, or two functions use pass-by-reference in the project code.                  | Multiple funtions using pass-by-reference such as: (`renderer.h` line 19)  (`game.h` line 17) (`snake.h` line 54).                    |
| :heavy_check_mark: | The project uses smart pointers instead of raw pointers.      | The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. The project does not use raw pointers. | In `renderer.h`, lines 27 & 28, attributes are changed from raw pointers to shared pointers. Raw pointers are not used anywhere else. |
### Concurrency

|                    | Criteria                                | Meets Specifications                                                                                                                               | Notes                                                                                                                                                                                                                                                                            |
|--------------------|-----------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| :heavy_check_mark: | The project uses multithreading.        | The project uses multiple threads in the execution.                                                                                                | Threads launched in:  1. `Game.cpp` line 15, using the `Game::runThread()` function.  2. `Controller.cpp` line 75, using the `Controller::runThread()` function.  These threads handle the game engine and the input controller respectively.                                    |
| :heavy_check_mark: | A mutex or lock is used in the project. | A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. | Used multiple times in project to protect resources shared by the Controller and Game.  In `game.cpp` line 132, `std::unique_lock` is used to lock the snake resource before using it.  In `ThreadObject.cpp` line 16, `std::lock_guard` used to lock the Running flag resource. |


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
