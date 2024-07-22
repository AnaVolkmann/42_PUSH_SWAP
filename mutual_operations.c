/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:43:49 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/22 15:44:39 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief rra and rrb at the same time.*/
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (*stack_a && *stack_b)
	{
		ft_rra(stack_a, 1);
		ft_rrb(stack_b, 1);
		if (i == 0)
			write(1, "rrr\n", 4);
	}
}

/** @brief sa and sb at the same time.*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (*stack_a && *stack_b)
	{
		ft_sa(stack_a, 1);
		ft_sb(stack_b, 1);
		if (i == 0)
			write(1, "ss\n", 3);
	}
}

/** @brief - ra and rb at the same time.*/
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (*stack_a && *stack_b)
	{
		ft_ra(stack_a, 1);
		ft_rb(stack_b, 1);
		if (i == 0)
			write(1, "rr\n", 3);
	}
}
