/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:13:14 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 19:15:54 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_new(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

int	is_sorted(t_stack *lst)
{
	t_stack	*aux;

	aux = lst;
	while (aux->next)
	{
		if (aux->nbr > aux->next->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	stack_len(t_stack *lst)
{
	t_stack	*aux;
	int		len;

	aux = lst;
	len = 0;
	while (aux)
	{
		len++;
		aux = aux->next;
	}
	return (len);
}

t_stack	*create_stack(char **argv, int argc)
{
	int		i;
	t_stack	*aux;
	t_stack	*a;

	i = 1;
	a = ft_lst_new(ft_atoi(argv[i]));
	aux = a;
	aux->prev = NULL;
	i++;
	while (i < argc)
	{
		aux->next = ft_lst_new(ft_atoi(argv[i]));
		i++;
		aux->next->prev = aux;
		aux = aux->next;
	}
	aux->next = NULL;
	return (a);
}
