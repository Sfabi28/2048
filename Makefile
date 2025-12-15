NAME        = 2048
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ./ft_printf
FT_PRINTF  = $(PRINTF_DIR)/libftprintf.a

LIBS        = -lncurses -L$(LIBFT_DIR) -lft

SRCS        = main.c init.c logic.c display.c movement.c utils.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re