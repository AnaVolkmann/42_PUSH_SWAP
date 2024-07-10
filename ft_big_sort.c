/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:54:58 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/10 15:10:18 by ana-lda-         ###   ########.fr       */
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

/* 
t_stack sort_b(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	
} */

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_list_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else if (ft_list_size(*stack_a) == 3)
		sort_three(stack_a);
}
