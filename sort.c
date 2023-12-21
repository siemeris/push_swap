/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:36:50 by issierra          #+#    #+#             */
/*   Updated: 2023/12/21 19:45:49 by issierra         ###   ########.fr       */
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
    //imprimir_lista(*ptr); 

    if ((*lst)->nbr > (*lst)->next->nbr)
        sa(lst);

    //ft_printf("ptr nbr %i\n", (*lst)->nbr);
    //ft_printf("ptr next next nbr %i", (*lst)->next->next->nbr);
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
// 4.2. Análisis de Costes.
// 4.3. Movemos el de menor coste a A.
// 4.4 4.2 y 4.3 hasta que no queden números en B.

void    init_data_ab(t_stack *a, t_stack *b)
{
    init_idx_medium(a);
    init_idx_medium(b);
    init_target_ab(a, b);
    init_cost_ab(a, b);
    // init_cheapest(a);
}

void    init_idx_medium(t_stack *lst)
{
    int med;
    int i;
    //t_stack *aux;

    //aux = lst;
    i = 0;
    med = stack_len(lst) / 2;

    while (lst)
    {
        lst->idx = i;
        lst->ab_medium = med;
        if (i < med)
            lst->ab_medium = 1;
        else
            lst->ab_medium = 0;
        lst = lst->next;
        i++;
    }

    // DEBUG: Impresión de la lista
    // lst = aux;
    // while (lst)
    // {
    //      ft_printf("idx %i\n nbr %i\n med %i\n", lst->idx, lst->nbr, lst->ab_medium);
    //      lst = lst->next;
    // }


}

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



void    init_target_ab(t_stack *a, t_stack *b)
{
    int closest_smaller;

    t_stack *auxa;
    t_stack *auxb;
    auxb = b;
    auxa = a;

    //imprimir_lista(a);
    //imprimir_lista(b);

    while (a)
    {
        closest_smaller = -2147483648;
        b = auxb;
        while(b)
        {
            //tenemos que encontrar el más cercano más pequeño
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

    //imprimimos la lista con la info
    a = auxa;
    while (a)
    {
        ft_printf("nbr %i\n target %i\n", a->nbr, a->target->nbr);
        a = a->next;
    }
}

void    init_cost_ab(t_stack *a, t_stack *b)
{
    imprimir_lista(a);
    imprimir_lista(b);

    t_stack *auxa;
    int     lena;
    int     lenb;

    auxa = a;
    lena = stack_len(a);
    lenb = stack_len(b);
    
    while(a)
    {
        // ft_printf("nbr %i\n", a->nbr);
        // ft_printf("idx %i\n", a->idx);
        // ft_printf("ab_medium %i\n", a->ab_medium);
        // ft_printf("target %i\n", a->target->nbr);
        // ft_printf("target idx %i\n", a->target->idx);
        // ft_printf("target ab_medium %i\n", a->target->ab_medium);
        // ft_printf("stack_len a %i\n", stack_len(a));
        a->cost = a->idx;
        if (a->ab_medium == 0)
        {
            a->cost = lena - (a->idx);
        }
        if (a->target->ab_medium == 1)
        {
            a->cost += a->target->idx;
        }
        else
            a->cost += lenb - a->target->idx;
        a = a->next;
    }

    a = auxa;
    //imprimimos la lista con la info
    while (a)
    {
        ft_printf("nbr %i\n cost %i\n", a->nbr, a->cost);
        a = a->next;
    }

}

void    sort(t_stack **a, t_stack **b)
{
    int    len;

    len = stack_len(*a);
    //ft_printf("len %i", len);
    //ft_printf("stack_len %i", stack_len(*b));

    if (len > 3 && !is_sorted(*a))
    {
        //ft_printf("no está ordenado");
        pb(a, b);
    }
    if (len > 3 && !is_sorted(*a))
    {
        //ft_printf("no está ordenado");
        pb(a, b);
    }
    init_data_ab(*a, *b);
    //sort_three(a);
    
    //imprimir_lista(*a);
    //imprimir_lista(*b);

}