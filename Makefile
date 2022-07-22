CC	= gcc -g

SOURCES	= minishell.c preparser.c preparser_utils.c preparser_two.c preparser_three.c parser.c parser_utils.c parser_d_quote.c parser_dollar.c

OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= minishell.h

NAME 	= minishell

LIB		= libft/libft.a

FLAGS 	=  -Werror -Wextra -Wall -I $(HEADER)

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJECTS)
	make -C libft
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -lreadline -L/Users/gantedil/.brew/opt/readline/lib -I/Users/gantedil/.brew/opt/readline/include -o $(NAME) 

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	make -C libft clean
	rm -f $(OBJECTS)

fclean	: clean
	make -C libft fclean
	rm -f $(NAME)

re	: fclean all