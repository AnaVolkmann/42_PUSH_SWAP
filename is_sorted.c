/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:33:23 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/08 18:17:56 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Checks if the stack is already in order.*/
int	is_sorted(t_stack *stack_a)
{
	int	current;

	current = stack_a->data;
	while (stack_a)
	{
		if (current > stack_a->data)
			return (0);
		current = stack_a->data;
		stack_a = stack_a->next;
	}
	return (1);
}
