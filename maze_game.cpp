#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constants
const int numRows = 10;
const int numCols = 10;
const char WALL = '+';
const char EMPTY = ' ';
const char PLAYER = 'P';
const char EXIT = 'E';
const char blockages = 'B';

// Maze Class
class Maze 
{
private:
    char** maze;
    int startRow, startCol;
    int numExits;
    int* exitRows;
    int* exitCols;
    int numBlockages;
    int* blockageRows;
    int* blockageCols;
    int playerRow, playerCol;

public:
    Maze() {
        srand(std::time(0)); // Set random seed
        allocateMaze();
    }

    ~Maze() {
        deallocateMaze();
    }

    void allocateMaze() {
        maze = new char* [numRows];
        for (int i = 0; i < numRows; i++) {
            maze[i] = new char[numRows];
        }

        exitRows = new int[numRows];
        exitCols = new int[numCols];
        blockageRows = new int[numRows];
        blockageCols = new int[numCols];
    }

    void deallocateMaze() {
        for (int i = 0; i < numRows; i++) {
            delete[] maze[i];
        }
        delete[] maze;
        delete[] exitRows;
        delete[] exitCols;
        delete[] blockageRows;
        delete[] blockageCols;
    }

    void generate() {
        // Initialize maze with empty spaces
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                maze[i][j] = EMPTY;
            }
        }

        // Place walls
        for (int i = 0; i < numRows; i++) {
            maze[i][0] = WALL;
            maze[i][numCols - 1] = WALL;
            maze[0][i] = WALL;
            maze[numCols - 1][i] = WALL;
        }

        // Place player at a random position
        playerRow = rand() % (numRows - 2) + 1;
        playerCol = rand() % (numCols - 2) + 1;
        maze[playerRow][playerCol] = PLAYER;

        // Place exits at random positions
        numExits = rand() % (numRows / 2) + 1;
        for (int i = 0; i < numExits; i++) {
            exitRows[i] = rand() % (numRows - 2) + 1;
            exitCols[i] = rand() % (numCols - 2) + 1;
            maze[exitRows[i]][exitCols[i]] = EXIT;
        }

        // Place blockages at random positions
        numBlockages = rand() % (numRows * numCols / 4);
        for (int i = 0; i < numBlockages; i++) {
            blockageRows[i] = rand() % (numRows - 2) + 1;
            blockageCols[i] = rand() % (numCols - 2) + 1;
            maze[blockageRows[i]][blockageCols[i]] = blockages;
        }
    }

    void display() {
      cout << "--Play Maze Game--" << endl;
      cout<<"  " <<endl;
  

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                cout << maze[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void updatePlayerPosition(char move) {
        // Update player position based on the move
        int newRow = playerRow;
        int newCol = playerCol;

        switch (move) {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
        default:
            return; // Invalid move, do nothing
        }

        // Check if the new position is valid
        if (maze[newRow][newCol] == WALL || maze[newRow][newCol] == blockages) {
            return; // Wall or blockage, cannot move there
        }

        // Update player position
        maze[playerRow][playerCol] = EMPTY;
        playerRow = newRow;
        playerCol = newCol;
        maze[playerRow][playerCol] = PLAYER;
    }

    bool checkExitReached() {
        for (int i = 0; i < numExits; i++) {
            if (playerRow == exitRows[i] && playerCol == exitCols[i]) {
                return true; // Exit reached
            }
        }
        return false; // Exit not reached
    }

  
};


// Main Function
int main() {
    Maze arb ;
    cout << "/////WELCOME TO MAZE GAME ////////////" << endl;
    cout<<"  " <<endl;
    arb.generate();
  
    char move;
    while (true) {
        arb.display();
        cout << "Enter your move (w/a/s/d): ";
        cin >> move;

        arb.updatePlayerPosition(move);
        system("clear");
        if (arb.checkExitReached()) {
            cout << "Congratulations! You reached the exit." << std::endl;

            break;
        }
    }

    return 0;
}

