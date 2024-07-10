/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:53 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:09 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief checks if imput is inside the max and min integers*/
int	error_int(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

/** @brief checks if the parameters are integers, also checks signs*/
int	error_syntax(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (!argv[i][j + 1] || !(argv[i][j + 1] >= '0' &&
					argv[i][j + 1] <= '9'))
					return (1);
			}
			else if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/** @brief checks for duplicate numbers*/
int	error_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/** @brief ckecks imput for all requesites*/
int	valid_imput(char **argv, int argc)
{
	if (!argv[0] || !argv[0][0] || error_syntax(argc, argv)
		|| error_int(argc, argv) || error_dup(argv))
		return (0);
	return (1);
}
