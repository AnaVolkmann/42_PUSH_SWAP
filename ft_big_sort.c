/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:54:58 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/20 19:25:31 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	right_pos_push(t_stack **stack, t_stack *target, char c)
{
	while (*stack != target)
	{
		if (target->above_median)
		{
			if (c == 'a')
				ft_ra(stack, 0);
			else
				ft_rb(stack, 0);
		}
		else
		{
			if (c == 'a')
				ft_rra(stack, 0);
			else
				ft_rrb(stack, 0);
		}
	}
}

void	send_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = ft_cheapest(stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			ft_rr(stack_a, stack_b, 0);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			ft_rrr(stack_a, stack_b, 0);
	right_pos_push(stack_a, cheapest, 'a');
	right_pos_push(stack_b, cheapest->target, 'b');
	ft_pb(stack_b, stack_a, 0);
}

void	send_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = ft_cheapest(stack_b);
	right_pos_push(stack_b, cheapest, 'b');
	right_pos_push(stack_a, cheapest->target, 'a');
	ft_pa(stack_a, stack_b, 0);
}

void	lowest_to_top(t_stack **stack_a)
{
	t_stack	*lowest;

	index_median(stack_a);
	lowest = ft_lowest(stack_a);
	while (lowest != *stack_a)
	{
		if (lowest->above_median)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(stack_a) == 2)
		ft_sa(stack_a, 0);
	else if (ft_stack_size(stack_a) == 3)
		sort_three(stack_a);
	if (ft_stack_size(stack_a) > 3)
		ft_pb(stack_b, stack_a, 0);
	if (ft_stack_size(stack_a) > 3)
		ft_pb(stack_b, stack_a, 0);
	while (ft_stack_size(stack_a) > 3)
	{
		update_stack_nodes(stack_a, stack_b, 'a');
		send_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		update_stack_nodes(stack_a, stack_b, 'b');
		send_b_to_a(stack_a, stack_b);
	}
	lowest_to_top(stack_a);
}
