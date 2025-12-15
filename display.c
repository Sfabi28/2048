#include "header.h"

void    drawboard(t_game *game)
{

    clear();

    mvprintw(1, 2, "2048 - ESC per uscire");
    // mvprintw(2, 2, "Score: %d", game->score);  quando implementero' lo score

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int screen_y = (i * 2) + 4;
            int screen_x = (j * 7) + 2;

            if (game->board[i][j] != 0)
            {
                mvprintw(screen_y, screen_x, "[%d]", game->board[i][j]);
            }
            else
            {
                mvprintw(screen_y, screen_x, "[ . ]");
            }
        }
    }

    refresh();
}