/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:33:07 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/22 15:38:26 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief (rotate a) - Shifts all elements by 1, 
 * first element becomes the last.*/
void	ft_ra(t_stack **stack_a, int i)
{
	t_stack	*last;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	last = ft_last_node(stack_a);
	(*stack_a)->prev = last;
	last->next = (*stack_a);
	(*stack_a)->next->prev = NULL;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

/** @brief (swap a) - Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void	ft_sa(t_stack **stack_a, int i)
{
	t_stack	*second;

	if (*stack_a == NULL)
		return ;
	second = (*stack_a)->next;
	if (ft_stack_size(stack_a) >= 3)
		second->next->prev = *stack_a;
	(*stack_a)->prev = second;
	(*stack_a)->next = second->next;
	second->prev = NULL;
	second->next = *stack_a;
	*stack_a = second;
	if (i == 0)
		write (1, "sa\n", 3);
}

/** @brief (reverse rotate a) - Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	ft_rra(t_stack **stack_a, int i)
{
	t_stack	*last;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	last = ft_last_node(stack_a);
	last->next = *stack_a;
	last->prev->next = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	(*stack_a)->prev = NULL;
	if (i == 0)
		write (1, "rra\n", 4);
}

/** @brief (push a) - Take the 1st element on top of 'b' and 
place it on top of 'a'. Do nothing if 'b' is empty.*/
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*temp_b;

	if (!*stack_b)
		return ;
	temp_b = *stack_b;
	*stack_b = temp_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	temp_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp_b;
	*stack_a = temp_b;
	if (i == 0)
		write(1, "pa\n", 3);
}
