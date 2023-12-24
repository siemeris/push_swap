/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:22:11 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 20:32:32 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chars(char**arg, int i)
{
	int	len;

	while (arg[i])
	{
		len = ft_strlen(arg[i]);
		while (len >= 1)
		{
			if (len -1 != 0 && (arg[i][len - 1] == 45 || arg[i][len - 1] == 43))
				return (ft_putendl_fd("Error\nNúmeros con + o - en medio", \
STDERR), 0);
			if (!((arg[i][len - 1] >= 48 && arg[i][len - 1] <= 57)
				|| (arg[i][len - 1] == 45) || (arg[i][len - 1] == 43)))
				return (ft_putendl_fd("Error\nCaracter no válido", STDERR), 0);
			if (len == 1 && (arg[i][len - 1] == 45
				|| arg[i][len - 1] == 43) && !arg[i][len])
				return (ft_putendl_fd("Error\nSólo signo y falta número", \
STDERR), 0);
			len--;
		}
		i++;
	}
	return (1);
}

static	int	repeated_numbers(int argc, char**arg, int i)
{
	int	j;

	while (i < argc - 1)
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
			{
				ft_putendl_fd("Error\nNúmeros repetidos", STDERR);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **arg, int i)
{
	int	j;

	if (!chars(arg, i))
		return (0);
	j = i;
	while (i < argc)
	{
		if (ft_atoi(arg[i]) > INT_MAX || ft_atoi(arg[i]) < INT_MIN)
		{
			ft_putendl_fd("Error\nNúmeros fuera de rango", 2);
			return (0);
		}
		i++;
	}
	if (!repeated_numbers(argc, arg, j))
		return (0);
	return (1);
}
