/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:36:50 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 09:50:48 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **lst)
{
    //si el maximo es el primero, lo mando al final (ra)
    if ((*lst)->nbr > (*lst)->next->nbr && (*lst)->nbr > (*lst)->next->next->nbr)
        ra(lst);
    //imprimir_lista(*ptr);
    // si el máximo es el del medio lo mando al final con rra 
    else if (((*lst)->next->nbr > (*lst)->nbr) && ((*lst)->next->nbr > (*lst)->next->next->nbr))
        rra(lst);

    if ((*lst)->nbr > (*lst)->next->nbr)
        sa(lst);
}

//PASOS PARA ORDENAR STACK DE MAS DE 3 NÚMEROS:
//1. Crear stack B
// Si en A hay más de 3 elementos empujamos un elemento a B y ordenamos los 3 restantes.
//2. Mientras stack A tenga más de 3 números:
// 2.1. Calcular nodo objetivo (el cercano más pequeño, 
// si no hay cercano más pequeño entonces el objetivo es el más grande)
// 2.2. Análisis de Costes. 
// 2.3. Movemos el de menor coste a B.
// 2.4 2.2 y 2.3 hasta que queden 3 números.
//3. Ordenamos los 3 números de A.
//4. Mientras no queden números en B:
// 4.1. Calcular nodo objetivo de B a A(el cercano más grande
// si no hay cercano más grande entonces el objetivo es el más pequeño)
// 4.3. Movemos el objetivo en A al índice cero.
// 4.4 4.2 y 4.3 hasta que no queden números en B.

void from_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    cheapest = *a;
    while (cheapest && cheapest->cheapest != 1)
    {
        cheapest = cheapest->next;
    }
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

    while(*a != cheapest)
    {
        if (cheapest->ab_medium == 1)
            ra(a);
        else
            rra(a);
		upd_idx_medium(*a);
    }
    while(*b != cheapest->target)
    {
        if (cheapest->target->ab_medium == 1)
            rb(b);
        else
            rrb(b);

		upd_idx_medium(*b);
    }
    pb(a, b);
}

void from_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *info_b;
    
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



void    sort(t_stack **a, t_stack **b)
{
    int    len;

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
    while (len > 3)
    {
        upd_idx_medium(*a);
    	upd_idx_medium(*b);
    	upd_target_ab(*a, *b);
    	upd_cost_ab(*a, *b);
    	upd_cheapest(*a);
        from_a_to_b(a,b);
        len = stack_len(*a);
    }
    sort_three(a);
    while(*b)
    {
		upd_idx_medium(*a);
    	upd_idx_medium(*b);
    	upd_target_ba(*a, *b);
    	from_b_to_a(a,b);  
    }
    upd_idx_medium(*a);
    reorder_a(a);
}