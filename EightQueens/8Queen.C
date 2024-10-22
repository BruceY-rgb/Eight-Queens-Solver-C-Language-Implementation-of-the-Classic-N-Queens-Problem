#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 8
int counter=0;

// 检查是否可以在 (row, col) 位置放置皇后
bool isSafe(char board[MAXN][MAXN], int row, int col) {
    // 检查列
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // 检查主对角线 (从左上到右下)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // 检查副对角线 (从右上到左下)
    for (int i = row, j = col; i >= 0 && j < MAXN; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
        }
    return true;
}

// 解决N皇后问题
void SolveQueen(char board[MAXN][MAXN], int row) {
    if (row == MAXN) {
        // 打印当前的解法
        counter++;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // 在当前行的每一列尝试放置皇后
    for (int j = 0; j < MAXN; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';  // 放置皇后
            SolveQueen(board, row + 1);  // 递归解决下一行
            board[row][j] = '.';  // 回溯，撤销当前皇后
        }
    }
}

int main(void) {
    // 初始化棋盘
    char board[MAXN][MAXN];
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            board[i][j] = '.';
        }
    }

    // 开始求解
    SolveQueen(board, 0);
    printf("%d",counter);

    return 0;
}
