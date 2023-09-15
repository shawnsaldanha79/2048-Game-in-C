# 2048 Game in C

This is a simple implementation of the classic 2048 game in C programming.

## Table of Contents

1. [Description](#description)
2. [Getting Started](#getting-started)
3. [Usage](#usage)
4. [Contributing](#contributing)
5. [License](#license)
6. [Acknowledgments](#acknowledgments)

## Description

The repository contains the source code (`2048.c`) and an executable file (`2048.exe`) for the 2048 game. Additionally, there's a mind map (`2048 Mind Map.pdf`) that illustrates the game's logic and flow.

## Getting Started

### Prerequisites

To compile and run the game from source code, you'll need:

- A C compiler.
- Support for the `conio.h` library, which is Windows-specific.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/notshawnsaldanha/2048-game-in-C.git
   ```

2. Compile the game:
   ```bash
   gcc -o 2048-game 2048.c
   ```

## Usage

1. Run the game:
   ```bash
   ./2048-game
   ```

2. Use the following keys to play:
   - W: Move tiles up
   - A: Move tiles left
   - S: Move tiles down
   - D: Move tiles right
   - Q: Quit the game

3. Try to reach the 2048 tile by merging tiles with the same value. The game ends when there are no valid moves left.

## Contributing

If you'd like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your changes to your fork.
5. Submit a pull request with a clear description of your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

This game is inspired by the original 2048 game created by Gabriele Cirulli.

