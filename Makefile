CC	= gcc

SOURCES	= mainfile.c buildins/ft_cd.c buildins/ft_echo.c buildins/ft_env.c buildins/ft_exit.c buildins/ft_export.c buildins/ft_pwd.c buildins/ft_unset.c

OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= minishell.h

NAME 	= minishell

LIB		= libft/libft.a

FLAGS 	= -Werror -Wextra -Wall -I $(HEADER) -fsanitize=address

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJECTS)
	make -C libft
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	make -C libft clean
	rm -f $(OBJECTS)

fclean	: clean
	make -C libft fclean
	rm -f $(NAME)

re	: fclean all