/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:18:34 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/10 12:29:20 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	if (!valid_imput(argv, argc))
		free_split(argc, argv, true);
	else
		stack_a = new_stack(argv);
	if (!is_sorted(stack_a))
		//sort_stack(stack_a, stack_b);
	free_split(argc, argv, false);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
