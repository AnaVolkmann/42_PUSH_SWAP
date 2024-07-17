/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:28 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/17 15:03:00 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief This function defines the index of each element of the stack
 * and marks if it is over the median.*/
void	index_median(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	int		median;

	median = ft_list_size(*stack) / 2;
	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		if (i < median)
			temp->above_median = true;
		else if (i > median)
			temp->above_median = false;
		i++;
		temp = temp->next;
	}
}

void	refine_cost(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	int size_a = ft_list_size(*stack_a);
	int size_b = ft_list_size(*stack_b);

	if (temp->above_median && temp->target->above_median)
	{
		temp->cost -= (temp->index < temp->target->index) ? temp->index : temp->target->index;
	}
	else
	{
		int cost_a = size_a - temp->index;
		int cost_b = size_b - temp->target->index;
		temp->cost -= (cost_a < cost_b) ? cost_a : cost_b;
	}
}

/** @brief this funcion defines the cost of sending an
 *  element of a to b*/
void	cost_of_a (t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->above_median)
			temp->cost = temp->index;
		else
			temp->cost = ft_list_size(*stack_a) - temp->index;
		if (temp->target->above_median)
			temp->cost += temp->target->index;
		else
			temp->cost += ft_list_size(*stack_b) - temp->target->index;
		refine_cost(temp, stack_a, stack_b);
		temp = temp->next;
	}
}

void	cost_of_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = *stack_b;
	while (temp)
	{
		if (temp->above_median)
			temp->cost = temp->index;
		else
			temp->cost = ft_list_size(*stack_a) - temp->index;
		if (temp->target->above_median)
			temp->cost += temp->target->index;
		else
			temp->cost += ft_list_size(*stack_b) - temp->target->index;
		refine_cost(temp, stack_b, stack_a);
		temp = temp->next;
	}
}