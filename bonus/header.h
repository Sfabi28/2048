#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <curses.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct s_game
{
    int     board[5][5];
    int     size;
    int     score;
    int     best_score_4;
    int     best_score_5;
    int     win;
    int     lose;
} t_game;

extern int g_resize;

//init.c
int     init_game(t_game *game);

//logic.c
void    add_cell(t_game *game);
int     handle_pressed(t_game *game, int pressed);
int     isover(t_game *game);

//display.c
void    draw_board(t_game *game);
void    draw_rectangle(int y, int x, int h, int w);

//movement.c
int     move_left(t_game *game);
int     move_right(t_game *game);
int     move_up(t_game *game);
int     move_down(t_game *game);

//utils.c
void    mirror(int *row, t_game *game);
int     align(int *row, t_game *game);
int     merge(int *row, t_game *game);
void    transpose(t_game *game);
int	    get_score_from_file(char *filename);
void	save_score_to_file(char *filename, int score);
void	load_best_score(t_game *game);
void	update_best_score(t_game *game);
int      get_bg_color(int val);

//main.c (per completezza)
int     menu(t_game *game);
void    sig_handler(int signum);
void    start_ncurses(void);

//ascii.c
void    ascii_art(int y, int x, int val);

#endif
