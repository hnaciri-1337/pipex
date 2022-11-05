NAME = pipex
SRCS = srcs/pipex.c srcs/pipex_utils.c
all: $(NAME)
$(NAME):
	@cd libft && make re && make clean && cd ..
	@cc $(SRCS) -o pipex libft.a
clean:
	@rm -f libft.a
fclean: clean
	@rm -f pipex
re: fclean all