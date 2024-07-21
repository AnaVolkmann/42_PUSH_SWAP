SRC = handle_errors.c push_swap.c init_stack.c frees.c sort_utils.c\
stack_utils.c operations_stack_a.c operations_stack_b.c\
mutual_operations.c ft_big_sort.c set_targets.c set_cost.c
OBJS = $(SRC:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
LIBFTA = ./libft/libft.a
LIBFTD = ./libft

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFTA)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

$(LIBFTA):
			$(MAKE) -C $(LIBFTD)

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFTD) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFTD) fclean

re:			fclean $(NAME)

.PHONY: all clean fclean re