#include "header.h"

void mirror(int *row, t_game *game) //specchia la riga
{
    int temp = row[0];
    row[0] = row[game->size - 1];
    row[game->size - 1] = temp;

    temp = row[1];
    row[1] = row[game->size - 2];
    row[game->size - 2] = temp;
}

void transpose(t_game *game)
{
    int temp;

    for (int i = 0; i < game->size; i++)
    {
        for (int j = i + 1; j < game->size; j++)
        {
            temp = game->board[i][j];
            game->board[i][j] = game->board[j][i];
            game->board[j][i] = temp;
        }
    }
}

int align(int *row, t_game *game) //sposta tutti i numeri a sinistra
{
    int moves = 0;
    int k = 0;

    for (int i = 0; i < game->size; i++)
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

int merge(int *row, t_game *game) //unisce i numeri uguali
{
    int moves = 0;

    for (int i = 0; i < game->size - 1; i++)
    {
        if (row[i] != 0 && row[i + 1] == row[i])
        {
            row[i] *= 2;
            row[i + 1] = 0;
            moves++;

            game->score += row[i];
            //aumentare lo score una volta che lo ho
        }
    }

    return (moves);
}
