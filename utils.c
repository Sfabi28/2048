#include "header.h"

void mirror(int *row) //specchia la riga
{
    int temp = row[0];
    row[0] = row[3];
    row[3] = temp;

    temp = row[1];
    row[1] = row[2];
    row[2] = temp;
}

void transpose(t_game *game)
{
    int temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            temp = game->board[i][j];
            game->board[i][j] = game->board[j][i];
            game->board[j][i] = temp;
        }
    }
}

int align(int *row) //sposta tutti i numeri a sinistra
{
    int moves = 0;
    int k = 0;

    for (int i = 0; i < 4; i++)
    {
        if (row[i] != 0)
        {
            if (k != i)
            {
                row[k] = row[i];
                row[i] = 0;
                moves = 1;
            }
            k++;
        }
    }
    return (moves);
}

int merge(int *row) //unisce i numeri uguali
{
    int moves = 0;

    for (int i = 0; i < 3; i++)
    {
        if (row[i] != 0 && row[i + 1] == row[i])
        {
            row[i] *= 2;
            row[i + 1] = 0;
            moves++;
            //aumentare lo score una volta che lo ho
        }
    }

    return (moves);
}