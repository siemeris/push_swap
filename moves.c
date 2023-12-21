/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:24:19 by issierra          #+#    #+#             */
/*   Updated: 2023/12/21 10:05:36 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **ptr)
{
    swap(ptr);
    ft_printf("sa\n");
}

void sb(t_stack **ptr)
{
    swap(ptr);
    ft_printf("sb\n");
}

void swap(t_stack **ptr)
{
    t_stack *third;
    t_stack *second;
    t_stack *first;

    first = *ptr;
    second = (*ptr)->next;
    third = NULL;

    if ((*ptr)->next->next)
        third = (*ptr)->next->next;

    *ptr = second;
    (*ptr)->next = first;
    (*ptr)->next->next = third;
}

t_stack	*ft_lst_last(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void ra(t_stack **ptr)
{
    rot(ptr);
    ft_printf("ra\n");
}

void rb(t_stack **ptr)
{
    rot(ptr);
    ft_printf("rb\n");
}

void rra(t_stack **ptr)
{
    rotr(ptr);
    ft_printf("rra\n");
}

void rrb(t_stack **ptr)
{
    rotr(ptr);
    ft_printf("rrb\n");
}


void rot(t_stack **ptr)
{
    t_stack *tmp;
    t_stack *last;

    last = *ptr;
    last = ft_lst_last(last);

    tmp = *ptr;
    *ptr = (*ptr)->next;
    last->next = tmp;
    last->next->next = NULL;
}

void rotr(t_stack **ptr)
{
    t_stack *tmp;
    t_stack *sec_last;
    t_stack *head;

    head = *ptr;
    tmp = *ptr;
    while (tmp && tmp->next)
    {
        sec_last = tmp;
		tmp = tmp->next;
    }
    //ft_printf("sec last nbr" "%i", sec_last->next->nbr);
    head = sec_last->next;
    sec_last->next = NULL;
    head->next = *ptr;
    *ptr = head;

    //imprimir_lista(*ptr);
}