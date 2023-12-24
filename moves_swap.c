/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 08:40:46 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 08:56:07 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack**b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	sa(t_stack **ptr)
{
	swap(ptr);
	ft_printf("sa\n");
}

void	sb(t_stack **ptr)
{
	swap(ptr);
	ft_printf("sb\n");
}

void	swap(t_stack **ptr)
{
	t_stack	*third;
	t_stack	*second;
	t_stack	*first;

	first = *ptr;
	second = (*ptr)->next;
	third = NULL;
	if ((*ptr)->next->next)
		third = (*ptr)->next->next;
	*ptr = second;
	(*ptr)->next = first;
	(*ptr)->next->next = third;
}
