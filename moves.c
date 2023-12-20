/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:24:19 by issierra          #+#    #+#             */
/*   Updated: 2023/12/20 18:48:00 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *ptr)
{
    int tmp;

    tmp = ptr->nbr;
    ptr->nbr = ptr->next->nbr;
    ptr->next->nbr = tmp;
    ft_printf("sa\n");
}

void sa1(t_stack **ptr)
{
    t_stack *third;
    t_stack *second;
    t_stack *first;

    first = *ptr;
    second = (*ptr)->next;
    third = (*ptr)->next->next;

    *ptr = second;
    (*ptr)->next = first;
    (*ptr)->next->next = third;
    (*ptr)->next->next->next = NULL;

    ft_printf("sa\n");
}

t_stack	*ft_lst_last(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void ra(t_stack **ptr)
{
    t_stack *tmp;
    t_stack *last;

    last = *ptr;
    last = ft_lst_last(last);

    // tmp = ptr->nbr;
    // ptr->nbr = last->nbr;
    // last->nbr = tmp;

    // tmp = ptr->nbr;
    // ptr->nbr = ptr->next->nbr;
    // ptr->next->nbr = tmp;

    tmp = *ptr;
    *ptr = (*ptr)->next;
    last->next = tmp;
    last->next->next = NULL;

    //imprimir_lista(*ptr);
    ft_printf("ra\n");
}

void rra(t_stack **ptr)
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
    ft_printf("rra\n");
}

// int swap(char* arr)
// {
//     int temp;
    
//     temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//     return(0);
// }

// int push(char* arrA, char* arrB)
// {
//     int i;
//     int j;
//     int temp;

//     i = 0;
//     j = 0;
//     while (arrA[i] != '\0')
//         i++;
//     while (arrB[j] != '\0')
//         j++;
//     temp = arrA[i - 1];
//     arrA[i - 1] = arrB[j - 1];
//     arrB[j - 1] = temp;
//     return(0);
// }