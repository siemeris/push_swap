/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:36:50 by issierra          #+#    #+#             */
/*   Updated: 2023/12/21 09:54:52 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **lst)
{
    //t_stack *aux;
    //t_stack **ptr;

    //aux = *lst;

    //ptr apunta a t_stack *lst
    //ptr = lst;


    //si el maximo es el primero, lo mando al final (ra)
    if ((*lst)->nbr > (*lst)->next->nbr && (*lst)->nbr > (*lst)->next->next->nbr)
        ra(lst);
    //imprimir_lista(*ptr);
    // si el máximo es el del medio lo mando al final con rra 
    else if (((*lst)->next->nbr > (*lst)->nbr) && ((*lst)->next->nbr > (*lst)->next->next->nbr))
        rra(lst);
    //imprimir_lista(*ptr); 

    if ((*lst)->nbr > (*lst)->next->nbr)
        sa(lst);

    //ft_printf("ptr nbr %i\n", (*lst)->nbr);
    //ft_printf("ptr next next nbr %i", (*lst)->next->next->nbr);
}