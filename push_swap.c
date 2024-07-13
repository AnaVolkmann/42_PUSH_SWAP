/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:18:34 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/13 18:20:15 by ana-lda-         ###   ########.fr       */
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
	{
		ft_pb(&stack_b, &stack_a, 0);
		ft_pb(&stack_b, &stack_a, 0);
		ft_pb(&stack_b, &stack_a, 0);
		ft_target_in_b(&stack_a, &stack_b);
		//sort_stack(&stack_a);
		t_stack	*temp;
		temp = stack_a;
		while (temp)
		{
			ft_printf("%d->", temp->data);
			if (temp->target)
				ft_printf("target: %d", temp->target->data);
			ft_printf("\n");
			temp = temp->next;
		}
	}
	ft_printf("NULL\n");
	free_split(argc, argv, false);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
