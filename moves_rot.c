/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 08:39:44 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 08:51:03 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_last(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	rot(t_stack **ptr)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *ptr;
	last = ft_lst_last(last);
	tmp = *ptr;
	*ptr = (*ptr)->next;
	last->next = tmp;
	last->next->next = NULL;
}

void	rr(t_stack **a, t_stack**b)
{
	rot(a);
	rot(b);
	ft_printf("rr\n");
}

void	ra(t_stack **ptr)
{
	rot(ptr);
	ft_printf("ra\n");
}

void	rb(t_stack **ptr)
{
	rot(ptr);
	ft_printf("rb\n");
}
