/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:45:59 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/20 19:23:00 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief (rotate b) - Shifts all elements by 1,
 * first element becomes the last.*/
void	ft_rb(t_stack **stack_b, int i)
{
	t_stack	*last;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	last = ft_last_node(stack_b);
	(*stack_b)->prev = last;
	last->next = (*stack_b);
	(*stack_b)->next->prev = NULL;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	if (i == 0)
		write (1, "rb\n", 3);
}

/** @brief (swap b) - Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	ft_sb(t_stack **stack_b, int i)
{
	t_stack	*second;

	if (*stack_b == NULL)
		return ;
	second = (*stack_b)->next;
	if (ft_stack_size(stack_b) >= 3)
		second->next->prev = *stack_b;
	(*stack_b)->prev = second;
	(*stack_b)->next = second->next;
	second->prev = NULL;
	second->next = *stack_b;
	*stack_b = second;
	if (i == 0)
		write (1, "sb\n", 3);
}

/** @brief (reverse rotate b) - Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	ft_rrb(t_stack **stack_b, int i)
{
	t_stack	*last;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	last = ft_last_node(stack_b);
	last->next = *stack_b;
	last->prev->next = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	(*stack_b)->prev = NULL;
	if (i == 0)
		write (1, "rrb\n", 4);
}

/** @brief (push b) - Take the 1st element on top of 'a' and 
place it on top of 'b'. Do nothing if 'a' is empty.*/
void	ft_pb(t_stack **stack_b, t_stack **stack_a, int i)
{
	t_stack	*temp;
	t_stack	*temp_a;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_b;
	temp_a = *stack_a;
	*stack_b = temp_a;
	*stack_a = (temp_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	(*stack_b)->next = temp;
	if (temp)
		temp->prev = *stack_b;
	(*stack_b)->prev = NULL;
	if (i == 0)
		write(1, "pb\n", 3);
}
