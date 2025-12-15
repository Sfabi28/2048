#include "header.h"

void    add_cell(t_game *game)
{
    int zeros = 0;

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++)
        {
            if (game->board[i][j] == 0)
                zeros++;
        }
    }
    
    if (zeros == 0)
        return;

    int index = rand() % zeros;
    int counter = 0;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game->board[i][j] == 0)
            {
                if (counter == index)
                {
                    int number = rand() % 10;
                    if (number == 0)
                        game->board[i][j] = 4;
                    else
                        game->board[i][j] = 2;
                    return;
                }
                counter++;
            }
        }
    }
}

int handle_pressed(t_game *game, int pressed)
{
    int moved = 0;

    switch (pressed)
    {
        case KEY_UP:
            moved = move_up(game);
            break;
        case KEY_DOWN:
            moved = move_down(game);
            break;
        case KEY_LEFT:
            moved = move_left(game);
            break;
        case KEY_RIGHT:
            moved = move_right(game);
            break;
        default:
            break;
    }

    return (moved);
}

int isover(t_game *game)
{
    for (int i = 0; i < 4; i++) //check se c'e' un blocco a WIN_VALUE
    {
        for (int j = 0; j < 4; j++)
        {
            if (game->board[i][j] == WIN_VALUE && game->win == 0)
            {
                game->win = 1;
                return (1);
            }
        }
    }

    for (int i = 0; i < 4; i++) //check se ci sono mosse disponibili
    {
        for (int j = 0; j < 4; j++)
        {
            if (i > 0 && game->board[i - 1][j] == game->board[i][j])
                return (0);
            
            if (j < 3 && game->board[i][j + 1] == game->board[i][j])
                return (0);
            
            if (game->board[i][j] == 0)
                return (0);
        }
    }

    return (2); //game over
}



