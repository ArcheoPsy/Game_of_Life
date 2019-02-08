/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Game of life
*/

#include <stdio.h>
#include <stdlib.h>

int condition_checker(int **board, int d, int u)
{
    int condition = 0;

    //CROSS
    if (board[d - 1][u] == 1)
        condition = condition + 1;
    if (board[d + 1][u]  == 1)
        condition = condition + 1;
    if (board[d][u - 1] == 1)
        condition = condition + 1;
    if (board[d][u + 1] == 1)
        condition = condition + 1;
    //DIAGO
    if (board[d - 1][u - 1] == 1)
        condition = condition + 1;
    if (board[d - 1][u + 1] == 1)
        condition = condition + 1;
    if (board[d + 1][u + 1] == 1)
        condition = condition + 1;
    if (board[d + 1][u - 1] == 1)
        condition = condition + 1;
    return (condition);
}

int **board_refresh(int **board)
{
    int u = 1;
    int condition = 0;

    for (int d = 1; d != 4; d = d + 1) {
        while (u != 4) {
            if (board[d][u] == 1) {
                condition = condition_checker(board, d, u);
                if (condition < 2 || condition > 3) {
                    board[d][u] = 0;
                }
            }
            else if (board[d][u] == 0) {
                condition = condition_checker(board, d, u);
                if (condition == 3) {
                    board[d][u] = 1;
                }
            }
            u = u + 1;
            condition = 0;
        }
        u = 1;
    }
    return (board);
}

int cell_count(int **board)
{
    int u = 1;
    int total = 0;

    for (int d = 1; d != 4; d = d + 1) {
        while (u != 4) {
            total = total + board[d][u];
            u = u + 1;
        }
        u = 1;
    }
    return (total);
}

int main(int ac, char **av)
{
    int **board = malloc(sizeof(int *) * 4);
    int total = 0;
    int i = 0;

    for (; i != 5; i = i + 1) {
        board[i] = malloc(sizeof(int) * 4);
        for (int j = 0; j != 5; j = j + 1) {
            if (i == 0 || i == 4)
                board[i][j] = -1;
            else {
                if (j == 0 || j == 4)
                    board[i][j] = -1;
                else
                    board[i][j] = 0;
            }
        }
    }
    total = cell_count(board);
    printf("total = %d\n", total);
    for (int d = 0; d != 5; d = d + 1) {
        for (int u = 0; u != 5; u = u + 1)
            if (board[d][u] >= 0)
                printf(" %d", board[d][u]);
            else
                printf("%d", board[d][u]);
        putchar('\n');
    }
    board = board_refresh(board);
    printf("REFRESH\n");
    for (int d = 0; d != 5; d = d + 1) {
        for (int u = 0; u != 5; u = u + 1)
            if (board[d][u] >= 0)
                printf(" %d", board[d][u]);
            else
                printf("%d", board[d][u]);
        putchar('\n');
    }
    total = cell_count(board);
    printf("total = %d\n", total);
    return (0);
}
