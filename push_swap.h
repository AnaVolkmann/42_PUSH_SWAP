/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:05:43 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:48:51 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;// the value of the node
	int				pos;// position of the node in the stack
	int				above_median;// flag to indicate if num is above median
	int				min_mov;// minimum moves required for operation
	struct s_stack	*target;// pointer to the target node
	struct s_stack	*next;// pointer to the next node in the list
	struct s_stack	*prev;// pointer to the previous node
}					t_stack;

/*....................HANDLE_ERRORS......................*/

int		error_int(int argc, char **argv);
int		error_syntax(int agrc, char **argv);
int		error_dup(char **argv);
int		valid_imput(char **argv, int argc);

/*........................FREES...........................*/

void	free_stack(t_stack *node);
int		free_split(int argc, char **argv, bool flag);

/*.....................INIT_STACK........................*/

t_stack	*new_stack(char **str);
t_stack	*new_node(char *str);

/*......................IS_SORTED.........................*/

int		is_sorted(t_stack *stack_a);

/*......................LIST_UTILS........................*/

int		ft_max(t_stack *stack_a);
int		ft_min(t_stack *stack_a);
int		ft_list_size(t_stack *lst);
t_stack	*ft_last_list(t_stack *lst);

/*......................OPERATIONS.........................*/

void	ft_ra(t_stack **stack_a, int i);
void	ft_sa(t_stack **stack_a, int i);
void	ft_rra(t_stack **stack_a, int i);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rb(t_stack **stack_b, int i);
void	ft_sb(t_stack **stack_b, int i);
void	ft_rrb(t_stack **stack_b, int i);
void	ft_pb(t_stack **stack_b, t_stack **stack_a, int i);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int i);

#endif