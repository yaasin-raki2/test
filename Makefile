NAME = minishell

SRCS = main.c remove_quotes.c flag.c expand.c build.c

CC = gcc

FLAGS =

LIBFT = libft

INCLUDES = $(LIBFT)/.

all:
	@make -C $(LIBFT)
	@#make bonus -C $(LIBFT)
	@$(CC) $(FLAGS) $(SRCS) -L $(LIBFT) -lft -lreadline -o $(NAME) -I $(INCLUDES) -fsanitize=address

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
