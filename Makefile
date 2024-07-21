SRC = handle_errors.c init_stack.c frees.c sort_utils.c\
stack_utils.c operations_stack_a.c operations_stack_b.c\
mutual_operations.c ft_big_sort.c set_targets.c set_cost.c
BONUS = ./bonus/checker.c ./bonus/checker_utils.c
OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
LIBFTA = ./libft/libft.a
LIBFTD = ./libft
CHECKER = checker

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFTA)
			$(CC) $(CFLAGS) push_swap.c $(OBJS) $(LIBFTA) -o $(NAME)

$(LIBFTA):
			$(MAKE) -C $(LIBFTD)

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

bonus : 	$(NAME) $(OBJS) $(OBJSBONUS)
			$(CC) $(CFLAGS) $(OBJS) $(OBJSBONUS) $(LIBFTA) -o $(CHECKER)

clean:
			$(RM) $(OBJS) $(OBJSBONUS) push_swap.o
			$(MAKE) -C $(LIBFTD) clean

fclean:		clean
			$(RM) $(NAME) $(CHECKER)
			$(MAKE) -C $(LIBFTD) fclean

re:			fclean all

.PHONY: all clean fclean re bonus