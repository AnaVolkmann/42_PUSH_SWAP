/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:33:56 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/21 18:10:01 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_error(char *imput, t_stack **stack_a, t_stack **stack_b, int flag)
{
	free(imput);
	free_stack(*stack_a);
	free_stack(*stack_b);
	if (flag == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	execute_checker(char *imput, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(imput, "pa\n") == 0)
		ft_pa(stack_a, stack_b, 1);
	else if (ft_strcmp(imput, "ra\n") == 0)
		ft_ra(stack_a, 1);
	else if (ft_strcmp(imput, "sa\n") == 0)
		ft_sa(stack_a, 1);
	else if (ft_strcmp(imput, "rra\n") == 0)
		ft_rra(stack_a, 1);
	else if (ft_strcmp(imput, "rrb\n") == 0)
		ft_rrb(stack_b, 1);
	else if (ft_strcmp(imput, "rb\n") == 0)
		ft_rb(stack_b, 1);
	else if (ft_strcmp(imput, "sb\n") == 0)
		ft_sb(stack_b, 1);
	else if (ft_strcmp(imput, "pb\n") == 0)
		ft_pb(stack_b, stack_a, 1);
	else if (ft_strcmp(imput, "rr\n") == 0)
		ft_rr(stack_a, stack_b, 1);
	else if (ft_strcmp(imput, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b, 1);
	else if (ft_strcmp(imput, "ss\n") == 0)
		ft_ss(stack_a, stack_b, 1);
	else
		free_error(imput, stack_a, stack_b, 0);
}

void	check_output(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(*stack_a);
	free_stack(*stack_b);
}

void	read_imput(t_stack **stack_a, t_stack **stack_b)
{
	char	*imput;

	imput = NULL;
	while (1)
	{
		imput = get_next_line(0);
		if (imput == NULL || ft_strcmp(imput, "\n") == 0)
		{
			free(imput);
			break ;
		}
		execute_checker(imput, stack_a, stack_b);
		free(imput);
	}
}
