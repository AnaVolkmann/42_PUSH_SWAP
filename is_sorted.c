/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:33:23 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/20 18:33:54 by ana-lda-         ###   ########.fr       */
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

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		ft_printf("NULL\n");
	else
	{
		tmp = *stack;
		while (tmp)
		{
			ft_printf("data: %i -> ", tmp->data);
			ft_printf("index: %i -> ", tmp->index);
			ft_printf("above median: %i -> ", tmp->above_median);
			ft_printf("cost to push: %i\n", tmp->cost);
			if (tmp->target)
				ft_printf("target node: %i\n", tmp->target->data);
			tmp = tmp->next;
		}
	}
}

