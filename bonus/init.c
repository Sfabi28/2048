#include "header.h"

int   init_game(t_game *game)
{

    int i = 1;

    while (i < WIN_VALUE)
        i *= 2;
    
    if (i != WIN_VALUE)
    {
        ft_printf("Error: WIN_VALUE must be a power of 2.\n");
        return 1;
    }

    game->win = 0;
    game->lose = 0;
    game->score = 0;
    game->size = 4;
    
    load_best_score(game);

    for (int i = 0; i < game->size; i++)
    {
        for (int j = 0; j < game->size; j++)
            game->board[i][j] = 0;
    }

    return 0;
}