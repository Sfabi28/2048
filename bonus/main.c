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

    if (has_colors())
    {
        start_color();
        
        init_pair(1, COLOR_WHITE, COLOR_BLACK);

        init_pair(2, COLOR_BLACK, COLOR_YELLOW); //2
        init_pair(3, COLOR_BLACK, COLOR_RED);   //4
        init_pair(4, COLOR_WHITE, COLOR_MAGENTA); //8
        init_pair(5, COLOR_WHITE, COLOR_BLUE);  //16
        init_pair(6, COLOR_BLACK, COLOR_GREEN); //32
        init_pair(7, COLOR_BLACK, COLOR_CYAN); //64
        init_pair(6, COLOR_BLACK, COLOR_WHITE); //128
        init_pair(7, COLOR_WHITE, COLOR_YELLOW); //256
        init_pair(8, COLOR_WHITE, COLOR_RED);   //512
        init_pair(9, COLOR_BLACK, COLOR_MAGENTA); //1024
        init_pair(10, COLOR_BLACK, COLOR_BLUE);  //2048
        init_pair(11, COLOR_BLACK, COLOR_GREEN);  //4096+

        bkgd(COLOR_PAIR(1));
    }
}

int menu(t_game *game)
{
    while (1)
    {
        timeout(100);
        clear();
        mvprintw(1, 0, "Welcome on 2048!");
        mvprintw(3, 0, "1) Start Game");
        if (game->size == 4)
            mvprintw(3, 14, "(4x4)");
        else
            mvprintw(3, 14, "(5x5)");
        mvprintw(4, 0, "2) Settings");
        mvprintw(6, 0, "Esc to quit  ");

        int answer = getch();
        if (answer == 27)
            return (1);
        else if (answer == '1')
            return (0);
        else if (answer == '2')
        {
            clear();
            mvprintw(1, 0, "Settings");
            mvprintw(3, 0, "1) 4x4 grid       ");
            mvprintw(4, 0, "2) 5x5 grid       ");
            mvprintw(6, 0, "Esc to menu  ");
            
            while (1)
            {
                answer = getch();
                if (answer == '1')
                {
                    game->size = 4;
                    load_best_score(game);
                    break;
                }
                else if (answer == '2')
                {
                    game->size = 5;
                    load_best_score(game);
                    break;
                }
                else if (answer == 27)
                    break;
            }
        }
    }
}

int main()
{
    t_game game;

    if (init_game(&game))
        return 1;
    
    start_ncurses();
    signal(SIGWINCH, sig_handler);

    srand(time(NULL));

    while (true)
    {

        if (menu(&game))
            break;

        for (int i = 0; i < game.size; i++)
        {
            for (int j = 0; j < game.size; j++)
            game.board[i][j] = 0;
        }

        game.score = 0;
        game.win = 0;

        add_cell(&game);
        add_cell(&game);
        draw_board(&game);

        timeout(100);

        while (true)
        {
            if (g_resize)
            {
                endwin();
                start_ncurses();
                timeout(100);
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

            int end_game = isover(&game);

            if (end_game == 1)
            {
                mvprintw(LINES - 1, 0, "Hai vinto! Premi ENTER per continuare o ESC per uscire.");
                int answer ;

                while (1)
                {
                    answer = getch();
                    if (answer == 27)
                    {
                        mvprintw(LINES - 1, 0, "                                                              ");
                        break;
                    }
                    if (answer == 10)
                    {
                        mvprintw(LINES - 1, 0, "                                                              ");
                        break;
                    }
                }
                if (answer == 27)
                    break;
            }
            else if (end_game == 2)
            {
                mvprintw(LINES - 1, 0, "GAME OVER! Premi un tasto per uscire.");
                getch();
                break;
            }
        }
    }

    update_best_score(&game);
    endwin();

    return 0;
}