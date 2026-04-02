# Sokoban Puzzle Game

A fully playable grid-based Sokoban puzzle game built in C++ using the SFML graphics library.

## Features
- Load levels from text files
- Move player using W/A/S/D or arrow keys
- Push crates onto storage locations to win
- Collision detection for walls and double-crate blocking
- Win condition detection with congratulations message
- Press R to reset the level at any time
- Boost unit tests for movement and win conditions

## Technologies
C++17, SFML, STL (2D vectors, std::map), Boost Unit Testing, Make

## How to Build and Run
```bash
make
./Sokoban level1.lvl
```

## Screenshots
![Sokoban Game](sokoban_gameplay.png)
