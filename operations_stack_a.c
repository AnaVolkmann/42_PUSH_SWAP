/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:33:07 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:39:46 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief (rotate a) - Shifts all elements by 1, 
 * first element becomes the last.*/
void	ft_ra(t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = ft_last_list(*stack_a);
	(*stack_a)->next = temp;
	*stack_a = temp->next;
	temp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

/** @brief (swap a) - Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void	ft_sa(t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (i == 0)
		write (1, "sa\n", 3);
}

/** @brief (reverse rotate a) - Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	ft_rra(t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = ft_last_list(*stack_a);
	temp->next = *stack_a;
	temp->prev->next = NULL;
	(*stack_a)->prev = temp;
	*stack_a = temp;
	(*stack_a)->prev = NULL;
	if (i == 0)
		write (1, "rra\n", 4);
}

/** @brief (push a) - Take the 1st element on top of 'b' and 
place it on top of 'a'. Do nothing if 'b' is empty.*/
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*temp;

	if (!stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	if (i == 0)
		write(1, "pa\n", 3);
}
