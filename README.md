# Maze Game

A simple console-based maze game implemented in C++. The player navigates through a randomly generated maze to find an exit. The maze includes walls, blockages, and one or more exits.

## Features
- Random maze generation.
- Player movement with the keys: `w` (up), `a` (left), `s` (down), `d` (right).
- Random placement of walls, blockages, and exits.
- Displays the maze after each move.
- Detects when the player reaches an exit.

## Gameplay

- The player starts at a random position inside the maze.
- The player can move in four directions: up (`w`), left (`a`), down (`s`), and right (`d`).
- Blockages (represented by `B`) and walls (represented by `+`) obstruct the player’s path.
- Exits (represented by `E`) are randomly placed in the maze, and the goal is to reach one of them.
- Once the player reaches an exit, the game congratulates the player.

## How to Play

1. Clone the repository:
   ```bash
     git clone https://github.com/yourusername/maze-game.git
2. Navigate to the project folder:

       cd maze-game

3. Compile the program using g++:

        g++ -o maze_game maze_game.cpp

4. Run the game:

           ./maze_game
