SRCS = ft_strlen.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strchr.c ft_strjoin.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
NAME = ../libft.a
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
%.o: %.c
	 @cc -o $@ -c $<
all : $(NAME)
clean :
	@rm -f $(OBJS) $(BONUSOBJS)
fclean : clean
	@rm -f $(NAME)
re : fclean all
