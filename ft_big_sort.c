/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:54:58 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/16 15:14:29 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (ft_list_size(*stack_a) == 3)
	{
		if (ft_biggest(stack_a) == *stack_a)
			ft_ra(stack_a, 0);
		else if (ft_biggest(stack_a) == (*stack_a)->next)
			ft_rra(stack_a, 0);
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a, 0);
	}
}

void	right_pos_push(t_stack **stack, t_stack *target, int flag)
{
	while (*stack != target)
	{
		if (target->above_median)
		{
			if (flag == 0)
				ft_ra(stack, 0);
			else
				ft_rb(stack, 0);
		}
		else
		{
			if (flag == 0)
				ft_rra(stack, 0);
			else
				ft_rrb(stack, 0);
		}
	}
}
 
void	send_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;

	cheapest = ft_cheapest(stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			ft_rr(stack_a, stack_b, 0);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		while (cheapest != *stack_a && cheapest->target != *stack_b)
			ft_rrr(stack_a, stack_b, 0);
	right_pos_push(stack_a, cheapest, 0);
	right_pos_push(stack_b, cheapest->target, 1);
	ft_pb(stack_b, stack_a, 0);
}

void	send_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;

	cheapest = ft_cheapest(stack_b);
	right_pos_push(stack_b, cheapest, 1);
	right_pos_push(stack_a, cheapest->target, 0);
	ft_pa(stack_a, stack_b, 0);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	**stack_b;

	stack_b = NULL;
	if (ft_list_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else if (ft_list_size(*stack_a) == 3)
		sort_three(stack_a);
	if (ft_list_size(*stack_a) > 3 && !is_sorted(*stack_a))
		ft_pb(&stack_b, stack_a, 0);
	if (ft_list_size(*stack_a) > 3 && !is_sorted(*stack_a))
		ft_pb(&stack_b, stack_a, 0);
	while (ft_list_size(*stack_a) > 3)
	{
		update_stack_nodes(stack_a, stack_b, 1);
		send_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		update_stack_nodes(stack_a, stack_b, 0);
		send_b_to_a(stack_a, stack_b);
	}
	//lowest_on_top
}
