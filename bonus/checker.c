/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:21:56 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/21 17:55:15 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return (free_split(argc, argv, true));
	else
		stack_a = new_stack(argv);
	if (argc == 2)
		free_split(argc, argv, false);
	read_imput(&stack_a, &stack_b);
	check_output(&stack_a, &stack_b);
}
