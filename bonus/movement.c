#include "header.h"

int move_left(t_game *game) //deve spostare a sinistra, unire, e poi spostare nuovamente
{
    int moves = 0;

    for (int i = 0; i < game->size; i++)
    {
        moves += align(game->board[i], game);
        moves += merge(game->board[i], game);
        moves += align(game->board[i], game);
    }

    return (moves);
}

int move_right(t_game *game) //come il move left ma prima deve specchiare la str
{
    int moves = 0;

    for (int i = 0; i < game->size; i++)
    {
        mirror(game->board[i], game);
        moves += align(game->board[i], game);
        moves += merge(game->board[i], game);
        moves += align(game->board[i], game);
        mirror(game->board[i], game);
    }

    return (moves);
}

int move_up(t_game *game) //transpose per scambiare righe e colonne per utilizzare moveup e down
{
    int moves = 0;

    transpose(game);
    moves = move_left(game);
    transpose(game);

    return (moves);
}


int move_down(t_game *game)
{
    int moves = 0;

    transpose(game);
    moves = move_right(game);
    transpose(game);

    return (moves);
}

