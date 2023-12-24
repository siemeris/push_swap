/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:10:26 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 16:42:22 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **lst)
{
	if ((*lst)->nbr > (*lst)->next->nbr
		&& (*lst)->nbr > (*lst)->next->next->nbr)
		ra(lst);
	else if (((*lst)->next->nbr > (*lst)->nbr)
		&& ((*lst)->next->nbr > (*lst)->next->next->nbr))
		rra(lst);
	if ((*lst)->nbr > (*lst)->next->nbr)
		sa(lst);
}

t_stack	*max(t_stack *lst)
{
	int		max;
	t_stack	*aux;

	max = -2147483648;
	while (lst)
	{
		if (lst->nbr > max)
		{
			max = lst->nbr;
			aux = lst;
		}
		lst = lst->next;
	}
	return (aux);
}

t_stack	*min(t_stack *lst)
{
	int		min;
	t_stack	*aux;

	min = 2147483647;
	while (lst)
	{
		if (lst->nbr < min)
		{
			min = lst->nbr;
			aux = lst;
		}
		lst = lst->next;
	}
	return (aux);
}

void	reorder_a(t_stack **a)
{
	while ((*a)->nbr != min(*a)->nbr)
	{
		if (min(*a)->ab_medium)
			ra(a);
		else
			rra(a);
	}
}
