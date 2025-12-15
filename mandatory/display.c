#include "header.h"

void    draw_board(t_game *game)
{

    clear();

    mvprintw(1, 2, "2048 - ESC per uscire");
    mvprintw(2, 2, "Score: %d", game->score);

    for (int i = 0; i < game->size; i++)
    {
        for (int j = 0; j < game->size; j++)
        {
            int screen_y = (i * 2) + 4;
            int screen_x = (j * 7) + 2;

            if (game->board[i][j] != 0)
            {
                mvprintw(screen_y, screen_x, "[ %d ]", game->board[i][j]);
            }
            else
            {
                mvprintw(screen_y, screen_x, "[ . ]");
            }
        }
    }

    refresh();
}