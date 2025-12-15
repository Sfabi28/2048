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
    
    srand(time(NULL));

    add_cell(&game);
    add_cell(&game);
    draw_board(&game);

    while (true)
    {
        if (g_resize)
        {
            endwin();
            start_ncurses();
            draw_board(&game);
            g_resize = 0;
        }

        int pressed = getch();

        if (pressed == 27)
            break;

        int moved = handle_pressed(&game, pressed);

        if (moved)
        {
            add_cell(&game);
            draw_board(&game);
        }

        // int end_game = is_over(&game);

        // if (end_game == 1)
        //     handle_rematch(&game);
        // else if (end_game == 2)
        // {
        //     handle_end(&game);
        //     break;
        // }
    }

    endwin();

    return 0;
}