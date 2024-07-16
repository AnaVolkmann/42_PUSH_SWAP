/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:56:45 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/16 13:21:39 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Finds and returns the smallest number in the stack. */
t_stack	*ft_lowest(t_stack **stack_a)
{
	t_stack	*lowest;
	t_stack	*temp;

	temp = *stack_a;
	lowest = temp;
	while (temp)
	{
		if (temp->data < lowest->data)
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}

/** @brief Finds and returns the biggest number in the stack. */
t_stack	*ft_biggest(t_stack **stack_a)
{
	t_stack	*biggest;
	t_stack	*temp;

	temp = *stack_a;
	biggest = temp;
	while (temp)
	{
		if (temp->data > biggest->data)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
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

/** @brief returns the element that takes the list movements to push*/
t_stack	*ft_cheapest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

	temp = *stack;
	cheapest = temp;
	while (temp)
	{
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}
