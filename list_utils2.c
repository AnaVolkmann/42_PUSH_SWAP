/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:47 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/13 18:10:47 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_target_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *biggest_b;
	t_stack *best_target;
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = *stack_a;
	biggest_b = ft_biggest(stack_b);
	while (temp_a)
	{
		best_target = NULL;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (temp_a->data > temp_b->data && (!best_target ||
			 temp_b->data > best_target->data))
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

