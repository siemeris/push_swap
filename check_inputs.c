/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:22:11 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 18:47:11 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chars(char**arg)
{
	int	i;
	int	len;

	i = 1;
	while (arg[i])
	{
		len = ft_strlen(arg[i]);
		while (len >= 1)
		{
			if (len -1 != 0 && (arg[i][len - 1] == 45 || arg[i][len - 1] == 43))
			{
				ft_printf("Error\nNúmeros con caracter + o - en medio");
				return (0);
			}
			if (!((arg[i][len - 1] >= 48 && arg[i][len - 1] <= 57)
				|| (arg[i][len - 1] == 45) || (arg[i][len - 1] == 43)))
			{
				ft_printf("Error\nCaracter no válido");
				return (0);
			}
			len--;
		}
		i++;
	}
	return (1);
}

static	int	repeated_numbers(int argc, char**arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
			{
				ft_printf("Error\nNúmeros repes %i", ft_atoi(arg[i]));
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **arg)
{
	int	i;

	if (!chars(arg))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(arg[i]) > 2147483647 || ft_atoi(arg[i]) < -2147483648)
		{
			ft_printf("Error\nNúmeros fuera de rango");
			return (0);
		}
		i++;
	}
	if (!repeated_numbers(argc, arg))
		return (0);
	return (1);
}
