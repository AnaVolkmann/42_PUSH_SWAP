SRC = ft_memset.c ft_strlcpy.c ft_bzero.c ft_calloc.c ft_split.c\
ft_atol.c ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c\
ft_putpointer.c ft_putpointerhexa.c ft_putstr.c ft_puthexa.c\
get_next_line.c
OBJS = ${SRC:.c=.o}
RM = rm -rf
CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = libft.a

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
