/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:45:59 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:46:12 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief (rotate b) - Shifts all elements by 1,
 * first element becomes the last.*/
void	ft_rb(t_stack **stack_b, int i)
{
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = ft_last_list(*stack_b);
	(*stack_b)->next = temp;
	*stack_b = temp->next;
	temp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

/** @brief (swap b) - Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	ft_sb(t_stack **stack_b, int i)
{
	t_stack	*temp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (i == 0)
		write (1, "sb\n", 3);
}

/** @brief (reverse rotate b) - Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	ft_rrb(t_stack **stack_b, int i)
{
	t_stack	*temp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = ft_last_list(*stack_b);
	temp->next = *stack_b;
	temp->prev->next = NULL;
	(*stack_b)->prev = temp;
	*stack_b = temp;
	(*stack_b)->prev = NULL;
	if (i == 0)
		write (1, "rrb\n", 4);
}

/** @brief (push b) - Take the 1st element on top of 'a' and 
place it on top of 'b'. Do nothing if 'a' is empty.*/
void	ft_pb(t_stack **stack_b, t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
	{
		(*stack_a)->prev = NULL;
	}
	(*stack_b)->next = temp;
	if (temp)
		temp->prev = *stack_b;
	(*stack_b)->prev = NULL;
	if (i == 0)
		write(1, "pb\n", 3);
}
