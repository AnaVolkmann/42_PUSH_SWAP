/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:47 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/20 19:30:11 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief this funcion sets the best targets for each 
 * element of statck a in stack b; */
void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*biggest_b;
	t_stack	*best_target;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	biggest_b = ft_biggest(stack_b);
	while (temp_a)
	{
		best_target = NULL;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (temp_b->data < temp_a->data && (!best_target
					|| temp_b->data > best_target->data))
				best_target = temp_b;
			temp_b = temp_b->next;
		}
		if (!best_target)
			temp_a->target = biggest_b;
		else
			temp_a->target = best_target;
		temp_a = temp_a->next;
	}
}

/** @brief this funcion sets the best targets for each element
 *  of stack b in stack a; */
void	set_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*best_target;
	t_stack	*lowest;

	temp_b = *stack_b;
	lowest = ft_lowest(stack_a);
	while (temp_b)
	{
		best_target = NULL;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data && (!best_target
					|| temp_a->data < best_target->data))
				best_target = temp_a;
			temp_a = temp_a->next;
		}
		if (!best_target)
			temp_b->target = lowest;
		else
			temp_b->target = best_target;
		temp_b = temp_b->next;
	}
}

void	update_stack_nodes(t_stack **stack_a, t_stack **stack_b, char c)
{
	index_median(stack_a);
	index_median(stack_b);
	if (c == 'a')
	{
		set_target_a(stack_a, stack_b);
		cost_of_a(stack_a, stack_b);
	}
	else
	{
		set_target_b(stack_a, stack_b);
		cost_of_b(stack_a, stack_b);
	}
}
