CC	= gcc -g

SOURCES	= minishell.c preparser.c preparser_utils.c preparser_two.c preparser_three.c parser.c parser_utils.c parser_d_quote.c parser_dollar.c create_struct.c parse_dollar_two.c parser_words.c get_list_word.c struct_utils.c struct_utils_two.c

OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= headers

NAME 	= minishell

LIB		= libft/libft.a

FLAGS 	=  -Werror -Wextra -Wall  -I $(HEADER)

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJECTS)
	make -C libft
	make -C libft bonus
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