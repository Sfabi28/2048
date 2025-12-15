#include "header.h"

static const char *g_digits[10][3] = {
    {
        " _ ",
        "| |",
        "|_|"
    },
    {
        "   ",
        "  |",
        "  |"
    },
    {
        " _ ",
        " _|",
        "|_ "
    },
    {
        " _ ",
        " _|",
        " _|"
    },
    {
        "   ",
        "|_|",
        "  |"
    },
    {
        " _ ",
        "|_ ",
        " _|"
    },
    {
        " _ ",
        "|_ ",
        "|_|"
    },
    {
        " _ ",
        "  |",
        "  |"
    },
    {
        " _ ",
        "|_|",
        "|_|"
    },
    {
        " _ ",
        "|_|",
        " _|"
    }
};

void    ascii_art(int y, int x, int val)
{
    char *str_num = ft_itoa(val); 
    if (!str_num)
        return;

    int len = ft_strlen(str_num);
    
    int digit_width = 3; 
    int spacing = 1;
    int total_width = (len * digit_width) + ((len - 1) * spacing);

    int start_x = x + (21 / 2) - (total_width / 2);
    
    int start_y = y + 2;

    for (int row = 0; row < 3; row++)
    {
        int current_x = start_x;

        for (int i = 0; i < len; i++)
        {
            int digit = str_num[i] - '0';

            mvprintw(start_y + row, current_x, "%s", g_digits[digit][row]);
            
            current_x += digit_width + spacing;
        }
    }

    free(str_num);
}