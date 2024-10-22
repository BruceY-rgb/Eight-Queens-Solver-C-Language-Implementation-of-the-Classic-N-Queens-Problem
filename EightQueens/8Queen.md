# The Eight Queen Code in C
## 1.对回溯算法的理解
- 回溯算法实际上就是对决策树的遍历，但是实际上我们并不需要构建一棵真正的树。这棵树是抽象的，可以用通过构建数组的方式实现。
- 回溯算法的关键就是回溯之后要进行复原，这在接下来的代码实现之后会进行详细说明
- 回溯算法最核心的两个步骤就是构建决策树和检查结点两个关键步骤

## 2.八皇后问题的实现
### *2.1 构建决策树的函数*

```C
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
```

> 这里我们直接使用棋盘作为我们的决策依据，逐行向下进行。实际上这里的决策树就是这个棋盘，决策树的每一层对应的就是每一行皇后的情况。

- 多数情况下我们构建决策的部分都是一个递归程序，然后通过判断函数进行**check**。所以我们总是要有一个递归出口，这个出口就是当我们遍历完所有行时，***行数这个参数一定要比n皇后的n多1***.

### *2.2 判断结点是否合理的决策函数*

``` C
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
```

> 由于我们是逐行递增进行处理的，在同一行上不可能存在两个皇后。我们只需要检查同一列、主对角线和副对角线上是否存在***attack***的情况即可。

## 3.结论

通过运行程序我们发现，八皇后在不考虑对称、镜像等问题时一共有92个解。