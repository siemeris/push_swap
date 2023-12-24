/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:24:19 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 08:54:28 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack**b)
{
	rotr(a);
	rotr(b);
	ft_printf("rrr\n");
}

void	rra(t_stack **ptr)
{
	rotr(ptr);
	ft_printf("rra\n");
}

void	rrb(t_stack **ptr)
{
	rotr(ptr);
	ft_printf("rrb\n");
}

void	rotr(t_stack **ptr)
{
	t_stack	*tmp;
	t_stack	*sec_last;
	t_stack	*head;

	head = *ptr;
	tmp = *ptr;
	while (tmp && tmp->next)
	{
		sec_last = tmp;
		tmp = tmp->next;
	}
	head = sec_last->next;
	sec_last->next = NULL;
	head->next = *ptr;
	*ptr = head;
}
