#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SIZE 4

int grid[SIZE][SIZE];
char playerName[50];
int score = 0;

void initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid() {
    system("cls");
    printf("Player: %s\tScore: %d\n\n", playerName, score);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf(".\t");
            } else {
                printf("%d\t", grid[i][j]);
            }
        }
        printf("\n\n");
    }
}

void placeRandomTile() {
    int emptyCells[SIZE * SIZE][2];
    int numEmptyCells = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                emptyCells[numEmptyCells][0] = i;
                emptyCells[numEmptyCells][1] = j;
                numEmptyCells++;
            }
        }
    }

    if (numEmptyCells > 0) {
        int index = rand() % numEmptyCells;
        int value = (rand() % 2 + 1) * 2;
        int row = emptyCells[index][0];
        int col = emptyCells[index][1];
        grid[row][col] = value;
    }
}

void moveTiles(char direction) {
    int moved = 0;

    switch (direction) {
        case 'w':
            for (int j = 0; j < SIZE; j++) {
                for (int i = 1; i < SIZE; i++) {
                    if (grid[i][j] != 0) {
                        int row = i;
                        while (row > 0 && grid[row - 1][j] == 0) {
                            grid[row - 1][j] = grid[row][j];
                            grid[row][j] = 0;
                            row--;
                            moved = 1;
                        }
                        if (row > 0 && grid[row - 1][j] == grid[row][j]) {
                            grid[row - 1][j] *= 2;
                            score += grid[row - 1][j];
                            grid[row][j] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 'a':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 1; j < SIZE; j++) {
                    if (grid[i][j] != 0) {
                        int col = j;
                        while (col > 0 && grid[i][col - 1] == 0) {
                            grid[i][col - 1] = grid[i][col];
                            grid[i][col] = 0;
                            col--;
                            moved = 1;
                        }
                        if (col > 0 && grid[i][col - 1] == grid[i][col]) {
                            grid[i][col - 1] *= 2;
                            score += grid[i][col - 1];
                            grid[i][col] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 's':
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    if (grid[i][j] != 0) {
                        int row = i;
                        while (row < SIZE - 1 && grid[row + 1][j] == 0) {
                            grid[row + 1][j] = grid[row][j];
                            grid[row][j] = 0;
                            row++;
                            moved = 1;
                        }
                        if (row < SIZE - 1 && grid[row + 1][j] == grid[row][j]) {
                            grid[row + 1][j] *= 2;
                            score += grid[row + 1][j];
                            grid[row][j] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 'd':
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE - 2; j >= 0; j--) {
                    if (grid[i][j] != 0) {
                        int col = j;
                        while (col < SIZE - 1 && grid[i][col + 1] == 0) {
                            grid[i][col + 1] = grid[i][col];
                            grid[i][col] = 0;
                            col++;
                            moved = 1;
                        }
                        if (col < SIZE - 1 && grid[i][col + 1] == grid[i][col]) {
                            grid[i][col + 1] *= 2;
                            score += grid[i][col + 1];
                            grid[i][col] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;

        default:
            break;
    }

    if (moved) {
        placeRandomTile();
    }
}

int isGameOver() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(0)); // Seed the random number generator
    int highestScore = 0;
    char playAgain;
    do {
        printf("Enter your name: ");
        scanf("%s", playerName);
        getchar();
        score = 0; // Reset the score before each game
        initializeGrid(); // Reset the grid before each game
        placeRandomTile();
        placeRandomTile();
        printGrid();
        printf("Highest Score: %d\n", highestScore);
        char move;
        while (1) {
            move = getch();

            if (move == 'q') {
                printf("You quit the game. Your score is: %d\n", score);
                break;
            }

            moveTiles(move);

            if (score > highestScore) {
                highestScore = score;
            }
            printGrid();
            printf("Highest Score: %d\n", highestScore);

            if (isGameOver()) {
                printf("Game Over! Your score is: %d\n", score);
                break;
            }
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        getchar();
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
