#include <iostream>
using namespace std;

char board[3][3];

// Initialize board
void initBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Display board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if(j < 2) cout << " |";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check win
bool checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Make move
void makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove(player);
    } else {
        board[row][col] = player;
    }
}

// Game function
void playGame() {
    initBoard();
    char player = 'X';

    while(true) {
        displayBoard();
        makeMove(player);

        if(checkWin()) {
            displayBoard();
            cout << "🎉 Player " << player << " wins!\n";
            break;
        }

        if(checkDraw()) {
            displayBoard();
            cout << "😐 It's a draw!\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char choice;
    cout<<"Made by yuvraj" ;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}