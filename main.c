#include <stdio.h>

void print_board(char board[3][3]) {
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

bool game_tie(char board[3][3]) {

    bool tie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = false;
                break;
            }
        }
        if (!tie) break;
    }
    if (tie) return true;
    else return false;
}

bool game_over(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; 
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; 
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; 
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; 
    }
    return game_tie(board);

    return false;
}

bool vaild_move(char board[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

void make_move(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char mark = 'X';

    while (!game_over(board)) {
        print_board(board);
        int row, col;
        if (mark == 'X') {
            printf("Player 1's turn [X]: ");
        } else {
            printf("Player 2's turn [0]: ");
        }
        scanf("%d %d", &row, &col);

        if (vaild_move(board, row, col)) {
            if (mark == 'X') {
                make_move(board, row, col, mark);
                mark = 'O';
            } else {
                make_move(board, row, col, mark);
                mark = 'X';
            }
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    print_board(board);
    if (game_over(board)) {
        if (mark == 'X') {
            printf("Player 2 (O) wins!\n");
        } else {
            printf("Player 1 (X) wins!\n");
        }
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}
