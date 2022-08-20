LIB = ../libft/libft.a

LIBN	=

CC = gcc

SOURCES_LIB = ../libft/*.c

SOURCES = pipex_bonus.c error_help_bonus.c help_with_cmd_bonus.c dop_help_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c help_with_hands_bonus.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADER = pipex_bonus.h

NAME = pipex

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -I $(HEADER)

.PHONY: all clean fclean re bonus

all	: $(NAME)

$(NAME)	: $(OBJECTS) $(HEADER) $(SOURCES_LIB)
	make -C ../libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(NAME)

clean	:
	make -C ../libft clean
	rm -f $(OBJECTS)

fclean	: clean
	make -C ../libft fclean
	rm -f $(NAME)

re	:  fclean all
