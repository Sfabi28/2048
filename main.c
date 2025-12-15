#include "header.h"

int g_resize = 0;

void sig_handler(int signum)
{
    (void)signum;
    g_resize = 1;
}

void start_ncurses(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int main()
{
    t_game game;

    if (init_game(&game))
        return 1;
    
    start_ncurses();
    signal(SIGWINCH, sig_handler);
    
    return 0;
}