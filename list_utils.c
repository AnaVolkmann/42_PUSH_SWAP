/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:56:45 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:33 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Finds and returns the smallest number in the stack. */
int	ft_min(t_stack *stack_a)
{
	int		current;

	current = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < current)
			current = stack_a->data;
		stack_a = stack_a->next;
	}
	return (current);
}

/** @brief Finds and returns the biggest number in the stack. */
int	ft_max(t_stack *stack_a)
{
	int		current;

	current = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > current)
			current = stack_a->data;
		stack_a = stack_a->next;
	}
	return (current);
}

/** @brief Returns the last node of the stack*/
t_stack	*ft_last_list(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/** @brief Conts the number of elements in the stack*/
int	ft_list_size(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
