/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:24:29 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/21 18:03:19 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../libft/libft.h"

void	read_imput(t_stack **stack_a, t_stack **stack_b);
void	check_output(t_stack **stack_a, t_stack **stack_b);
void	execute_checker(char *imput, t_stack **stack_a, t_stack **stack_b);
void	free_error(char *imput, t_stack **stack_a, t_stack **stack_b, int flag);

#endif