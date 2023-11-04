#include <stdio.h>
#include <stdlib.h>

#define WHITE 'O'
#define BLACK 'X'

int N;
char **board;
int **visited;  
void readBoard(char *path) {
    FILE *file = fopen(path, "r");
    
    fscanf(file, "%d\n", &N);
    board = (char **)malloc(N * sizeof(char *));
    visited = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (char *)malloc((N + 1) * sizeof(char));
        visited[i] = (int *)calloc(N, sizeof(int));  
        for (int j = 0; j < N; j++) {
            fscanf(file, " %c", &board[i][j]);
        }
        board[i][N] = '\0';  
    }

    fclose(file);
}

void freeBoard() {
    for (int i = 0; i < N; i++) {
        free(board[i]);
        free(visited[i]);
    }
    free(board);
    free(visited);
}

int isSurrounded(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;  
    }
    if (board[x][y] == BLACK || visited[x][y]) {
        return 1;  
    }
    if (board[x][y] == WHITE) {
        visited[x][y] = 1;  
        int up = isSurrounded(x, y - 1);
        int down = isSurrounded(x, y + 1);
        int left = isSurrounded(x - 1, y);
        int right = isSurrounded(x + 1, y);
        return up && down && left && right;
    }
    return 0;
}

void capture(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N || board[x][y] != WHITE || !visited[x][y]) {
        return;
    }
    board[x][y] = BLACK;
    capture(x, y - 1);
    capture(x, y + 1);
    capture(x - 1, y);
    capture(x + 1, y);
}

int getWinner(char *path) {
    readBoard(path);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == WHITE && !visited[i][j] && isSurrounded(i, j)) {
                capture(i, j);
            }
        }
    }

    int whiteCount = 0;
    int blackCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == WHITE) {
                whiteCount++;
            } else if (board[i][j] == BLACK) {
                blackCount++;
            }
        }
    }

    freeBoard();

    if (whiteCount > blackCount) {
        return 1;
    } else if (whiteCount < blackCount) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    printf("%d\n", getWinner("input.txt"));
    return 0;
}
