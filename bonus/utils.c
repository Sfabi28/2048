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

// Carica il punteggio dal file
void load_best_score(t_game *game)
{
    int     fd;
    char    buffer[20];
    int     bytes_read;

    game->best_score = 0;

    fd = open(".best_score", O_RDONLY);
    if (fd < 0)
        return;

    bytes_read = read(fd, buffer, 19);
    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        game->best_score = ft_atoi(buffer);
    }
    close(fd);
}

void update_best_score(t_game *game)
{
    int     fd;
    char    *score_str;

    if (game->score <= game->best_score)
        return;

    game->best_score = game->score;

    fd = open(".best_score", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return;

    score_str = ft_itoa(game->best_score);
    if (score_str)
    {
        write(fd, score_str, ft_strlen(score_str));
        free(score_str);
    }
    close(fd);
}