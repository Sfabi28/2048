#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <curses.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct s_game
{
    int     board[4][4];
    int     score;
    int     win;
    int     lose;
} t_game;

extern int g_resize;

//init.c
int    init_game(t_game *game);

//logic.c
void    add_cell(t_game *game);

//display.c
void    draw_board(t_game *game);

//main.c (per completezza)
void   sig_handler(int signum);

#endif