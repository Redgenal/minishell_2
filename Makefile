CC	= gcc

SOURCES	= mainfile.c buildins/ft_cd.c buildins/ft_echo.c buildins/ft_env.c \
		buildins/ft_exit.c buildins/ft_export.c buildins/ft_pwd.c buildins/ft_unset.c \
		help.c errors/error_help_bonus.c pipex/help_with_cmd_bonus.c pipex/get_next_line_bonus.c \
		pipex/get_next_line_utils_bonus.c redir.c errors/errors_in_redir.c job.c \
		pipex/dop_help_bonus.c
		
OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= minishell.h

NAME 	= minishell

LIB		= libft/libft.a

FLAGS 	= -Werror -Wextra -Wall -I $(HEADER) -fsanitize=address -g

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJECTS)
	make -C libft
	make -C libft bonus
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