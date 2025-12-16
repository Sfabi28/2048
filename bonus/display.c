#include "header.h"

void    draw_rectangle(int y, int x, int h, int w)
{
    mvhline(y, x, 0, w);
    mvhline(y + h - 1, x, 0, w);
    mvvline(y, x, 0, h);
    mvvline(y, x + w - 1, 0, h);
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x + w - 1, ACS_URCORNER);
    mvaddch(y + h - 1, x, ACS_LLCORNER);
    mvaddch(y + h - 1, x + w - 1, ACS_LRCORNER);
}


void    draw_board(t_game *game)
{
    int cell_w = 21;
    int cell_h = 7;
    int start_y = 5;
    int start_x = 4;

    int min_h = 5 + (game->size * (cell_h - 1)) + 5;
    int min_w = 4 + (game->size * (cell_w - 1)) + 4;

    clear();

    if (LINES < min_h || COLS < min_w)
    {
        mvprintw(LINES / 2, (COLS - 16) / 2, "Window too small");
        refresh();
        return;
    }

    mvprintw(1, 4, "2048 - ESC to quit");
    if (game->size == 4)
        mvprintw(2, 4, "Best Score (4x4): %d", game->best_score_4);
    else
        mvprintw(2, 4, "Best Score (5x5): %d", game->best_score_5);
    
    mvprintw(3, 4, "Score: %d", game->score);

    for (int i = 0; i < game->size; i++)
    {
        for (int j = 0; j < game->size; j++)
        {
            int y = start_y + (i * (cell_h - 1));
            int x = start_x + (j * (cell_w - 1));

            attron(COLOR_PAIR(1));
            draw_rectangle(y, x, cell_h, cell_w);
            attroff(COLOR_PAIR(1));

            if (game->board[i][j] != 0)
            {      
                int val = game->board[i][j];

                int color_id = get_bg_color(val);
                attron(COLOR_PAIR(color_id));

                for (int row = 1; row < cell_h - 1; row++)
                {
                    move(y + row, x + 1);
                    for (int col = 0; col < cell_w - 2; col++)
                        addch(' '); 
                }

                ascii_art(y, x, val);
                attroff(COLOR_PAIR(color_id));
            }
        }
    }

    refresh();
}