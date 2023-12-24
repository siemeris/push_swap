/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:36:50 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 11:13:37 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ab_rot_both(t_stack *cheapest, t_stack **a, t_stack **b)
{
	if (cheapest->ab_medium == 1 && cheapest->target->ab_medium == 1)
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			rr(a, b);
			upd_idx_medium(*a);
			upd_idx_medium(*b);
		}
	}
	else if (cheapest->ab_medium == 0 && cheapest->target->ab_medium == 0)
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			rrr(a, b);
			upd_idx_medium(*a);
			upd_idx_medium(*b);
		}
	}
}

void	from_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = *a;
	while (cheapest && cheapest->cheapest != 1)
	{
		cheapest = cheapest->next;
	}
	ab_rot_both(cheapest, a, b);
	while (*a != cheapest)
	{
		if (cheapest->ab_medium == 1)
			ra(a);
		else
			rra(a);
		upd_idx_medium(*a);
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->ab_medium == 1)
			rb(b);
		else
			rrb(b);
		upd_idx_medium(*b);
	}
	pb(a, b);
}

void	from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*info_b;

	info_b = *b;
	if (info_b->target->ab_medium == 1)
	{
		while (*a != info_b->target)
		{
			ra(a);
			upd_idx_medium(*a);
		}
	}
	if (info_b->target->ab_medium == 0)
	{
		while (*a != info_b->target)
		{
			rra(a);
			upd_idx_medium(*a);
		}
	}
	pa(a, b);
}

void	sort_aux(int len, t_stack **a, t_stack **b)
{
	while (len > 3)
	{
		upd_idx_medium(*a);
		upd_idx_medium(*b);
		upd_target_ab(*a, *b);
		upd_cost_ab(*a, *b);
		upd_cheapest(*a);
		from_a_to_b(a, b);
		len = stack_len(*a);
	}
	sort_three(a);
	while (*b)
	{
		upd_idx_medium(*a);
		upd_idx_medium(*b);
		upd_target_ba(*a, *b);
		from_b_to_a(a, b);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len > 3 && !is_sorted(*a))
	{
		pb(a, b);
		len = stack_len(*a);
	}
	if (len > 3 && !is_sorted(*a))
	{
		pb(a, b);
		len = stack_len(*a);
	}
	sort_aux(len, a, b);
	upd_idx_medium(*a);
	reorder_a(a);
}
