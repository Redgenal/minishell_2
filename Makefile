CC	= gcc -g

SOURCES	= minishell.c parser/preparser.c parser/preparser_utils.c parser/preparser_two.c parser/preparser_three.c parser/parser.c \
		parser/parser_utils.c parser/parser_d_quote.c parser/parser_dollar.c parser/create_struct.c parser/parse_dollar_two.c parser/parser_words.c \
		parser/get_list_word.c parser/struct_utils.c parser/struct_utils_two.c exequte/mainfile.c buildins/ft_cd.c \
		buildins/ft_echo.c buildins/ft_env.c buildins/ft_exit.c buildins/ft_export.c buildins/ft_pwd.c buildins/ft_unset.c \
		exequte/help.c errors/error_help_bonus.c pipex/help_with_cmd_bonus.c pipex/get_next_line_bonus.c parser/com_parse_api.c \
		pipex/get_next_line_utils_bonus.c exequte/redir.c errors/errors_in_redir.c exequte/job.c pipex/dop_help_bonus.c exequte/signals.c \
		exequte/signals_func.c exequte/mainfile_help.c exequte/new_help.c

OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= headers

NAME 	= minishell

LIB		= libft/libft.a

FLAGS 	=    -I $(HEADER)

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER)/*.h $(OBJECTS)
	make -C libft
	make -C libft bonus
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -lreadline -L/Users/gantedil/.brew/opt/readline/lib -I/Users/gantedil/.brew/opt/readline/include -o $(NAME) 

%.o	: %.c $(HEADER)/*.h
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	make -C libft clean
	rm -f $(OBJECTS)

fclean	: clean
	make -C libft fclean
	rm -f $(NAME)

re	: fclean all