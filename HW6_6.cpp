#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 4;

void drawBoard(char board[][BOARD_SIZE]) {
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    srand(time(0));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int randomIndex = rand() % 26;
            board[i][j] = letters[randomIndex];
        }
    }
}

bool isValidPosition(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

bool wordSearch(char board[][BOARD_SIZE], const char* word, int row, int col, int index) {
    if (board[row][col] != word[index]) {
        return 0;
    }

    if (word[index + 1] == '\0') {
        return 1;
    }

    char originalChar = board[row][col];
    board[row][col] = '*';

    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (isValidPosition(newRow, newCol) && wordSearch(board, word, newRow, newCol, index + 1)) {
            board[row][col] = originalChar;
            return 1;
        }
    }

    board[row][col] = originalChar;
    return 0;
}

void words_on_board(char board[][BOARD_SIZE], const char* wordsFile) {
    ifstream inputFile(wordsFile);
    if (!inputFile) {
        cout << "Error opening file: " << wordsFile << endl;
        return;
    }

    string word;
    while (inputFile >> word) {
        int index = 0;
        bool found = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (wordSearch(board, word.c_str(), i, j, index)) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        if (found) {
            cout << word << endl;
        }
    }

    inputFile.close();
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    drawBoard(board);
    cout << "The Game board:" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Valid words on the board:" << endl;
    words_on_board(board, "words.txt");
    return 0;
}
