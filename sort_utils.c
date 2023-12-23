/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:10:26 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 09:14:18 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *max(t_stack *lst)
{
    int max;
    t_stack *aux;

    max = -2147483648;
    while(lst)
    {
        if (lst->nbr > max)
        {
            max = lst->nbr;
            aux = lst;
        }
        lst = lst->next;
    }

    return aux;
}

t_stack *min(t_stack *lst)
{
    int min;
    t_stack *aux;

    min = 2147483647;
    while(lst)
    {
        if (lst->nbr < min)
        {
            min = lst->nbr;
            aux = lst;
        }
        lst = lst->next;
    }

    return aux;
}

void    reorder_a(t_stack **a)
{
    while ((*a)->nbr != min(*a)->nbr)
	{
		if (min(*a)->ab_medium)
			ra(a);
		else
			rra(a);
	}
}