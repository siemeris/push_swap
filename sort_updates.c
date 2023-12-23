/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_updates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:17:20 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 19:01:47 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upd_idx_medium(t_stack *lst)
{
	int	med;
	int	i;

	i = 0;
	med = stack_len(lst) / 2;
	while (lst)
	{
		lst->idx = i;
		lst->ab_medium = med;
		if (i <= med)
			lst->ab_medium = 1;
		else
			lst->ab_medium = 0;
		lst = lst->next;
		i++;
	}
}

void	upd_target_ab(t_stack *a, t_stack *b)
{
	int		closest_smaller;
	t_stack	*auxb;

	auxb = b;
	while (a)
	{
		closest_smaller = -2147483648;
		b = auxb;
		while (b)
		{
			if (b->nbr < a->nbr)
			{
				if (b->nbr > closest_smaller)
				{
					closest_smaller = b->nbr;
					a->target = b;
				}
			}
			b = b->next;
		}
		if (closest_smaller == -2147483648)
			a->target = max(auxb);
		a = a->next;
	}
}

void	upd_target_ba(t_stack *a, t_stack *b)
{
	int		closest_bigger;
	t_stack	*auxa;

	auxa = a;
	while (b)
	{
		closest_bigger = 2147483647;
		a = auxa;
		while (a)
		{
			if (b->nbr < a->nbr)
			{
				if (a->nbr < closest_bigger)
				{
					closest_bigger = a->nbr;
					b->target = a;
				}
			}
			a = a->next;
		}
		if (closest_bigger == 2147483647)
			b->target = min(auxa);
		b = b->next;
	}
}

void	upd_cost_ab(t_stack *a, t_stack *b)
{
	int	lena;
	int	lenb;

	lena = stack_len(a);
	lenb = stack_len(b);
	while (a)
	{
		a->cost = a->idx;
		if (a->ab_medium == 0)
			a->cost = lena - (a->idx);
		if (a->target->ab_medium == 1)
			a->cost += a->target->idx;
		else
			a->cost += lenb - a->target->idx;
		a = a->next;
	}
}

void	upd_cheapest(t_stack *a)
{
	t_stack	*auxa;
	int		cheapest;

	auxa = a;
	cheapest = 2147483647;
	while (a)
	{
		if (a->cost < cheapest)
			cheapest = a->cost;
		a = a->next;
	}
	a = auxa;
	while (a)
	{
		if (a->cost == cheapest)
			a->cheapest = 1;
		else
			a->cheapest = 0;
		a = a->next;
	}
}
