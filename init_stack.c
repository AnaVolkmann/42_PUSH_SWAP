/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:46:29 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:42 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Creates a new node.*/
t_stack	*new_node(char *str)
{
	t_stack	*node;

	node = NULL;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = ft_atol(str);
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/** @brief Links/creates stack.*/
t_stack	*new_stack(char **str)
{
	t_stack	*temp;
	t_stack	*current;
	t_stack	*stack;

	stack = NULL;
	current = new_node(*str);
	current->prev = NULL;
	stack = current;
	str++;
	while (*str)
	{
		temp = current;
		current = new_node(*str);
		if (!current)
		{
			free_stack(stack);
			return (NULL);
		}
		current->prev = temp;
		current->next = NULL;
		temp->next = current;
		str++;
	}
	return (stack);
}
