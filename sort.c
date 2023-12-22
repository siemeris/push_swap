/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:36:50 by issierra          #+#    #+#             */
/*   Updated: 2023/12/22 18:33:26 by issierra         ###   ########.fr       */
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
    init_cheapest(a);

    // while (a)
	// {
	// 	ft_printf("a->nbr: %i\n", a->nbr);
	// 	ft_printf("a->index: %d\n", a->idx);
	// 	ft_printf("a->above_median: %d\n", a->ab_medium);
	// 	ft_printf("a->target_node->nbr: %i\n", a->target->nbr);
	// 	ft_printf("a->target_node->nbr->idx: %i\n", a->target->idx);
    //     ft_printf("a->target_node->nbr->ab_medium: %i\n", a->target->ab_medium);
    //     ft_printf("a->push_cost: %d\n", a->cost);
	// 	ft_printf("a->cheapest: %d\n", a->cheapest);
	// 	ft_printf("\n");
	// 	a = a->next;
	// }
}

// void    init_data_ba(t_stack *a, t_stack *b)
// {
//     init_idx_medium(a);
//     init_idx_medium(b);
//     init_target_ba(a, b);
// }


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
        if (i <= med)
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
        //ft_printf("nbr %i\n target %i\n", a->nbr, a->target->nbr);
        a = a->next;
    }
}

void    init_target_ba(t_stack *a, t_stack *b)
{
    int closest_bigger;

    t_stack *auxa;
    t_stack *auxb;
    auxb = b;
    auxa = a;

    //imprimir_lista(a);
    //imprimir_lista(b);

    while (b)
    {
        closest_bigger = 2147483647;
        a = auxa;
        while(a)
        {
            //tenemos que encontrar el más cercano más grande
            if (b->nbr < a->nbr)
            {
                if (a->nbr < closest_bigger)
                {
                    closest_bigger = a->nbr;
                    b->target = a;
                }
            }
            a = a->next;
        }
        if (closest_bigger == 2147483647)
            b->target = min(auxa);
        b = b->next;
    }

    //imprimimos la lista con la info
    b = auxb;
    while (b)
    {
        //ft_printf("nbr %i\n target %i\n", b->nbr, b->target->nbr);
        b = b->next;
    }

}



void    init_cost_ab(t_stack *a, t_stack *b)
{
    //imprimir_lista(a);
    //imprimir_lista(b);

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
        //ft_printf("nbr %i\n cost %i\n", a->nbr, a->cost);
        a = a->next;
    }

}

void   init_cheapest(t_stack *a)
{
    t_stack *auxa;
    int     cheapest;

    auxa = a;
    cheapest = 2147483647;
    while (a)
    {
        if (a->cost < cheapest)
            cheapest = a->cost;
        a = a->next;
    }

    a = auxa;
    //establecemos el cheapest
    while (a)
    {
        if (a->cost == cheapest)
            a->cheapest = 1;
        else
            a->cheapest = 0;
        a = a->next;
    }
}

void from_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    //t_stack *auxa;
    //t_stack *auxb;

    //auxa = *a;
    //auxb = *b;
    cheapest = *a;
    while (cheapest && cheapest->cheapest != 1)
    {
        cheapest = cheapest->next;
    }
    ft_printf("cheapest %i", cheapest->nbr);

    if (cheapest->ab_medium == 1 && cheapest->target->ab_medium == 1)
    {
        while (*b != cheapest->target && *a != cheapest)
        {
            rr(a, b);
            init_idx_medium(*a);
            init_idx_medium(*b);
        }
    }
    else if (cheapest->ab_medium == 0 && cheapest->target->ab_medium == 0)
    {
        while (*b != cheapest->target && *a != cheapest)
        {
            rrr(a, b);
            init_idx_medium(*a);
            init_idx_medium(*b);
        }
    }

    while(*a != cheapest)
    {
        if (cheapest->ab_medium == 1)
        {
            ra(a);
            init_idx_medium(*a);
        }
        else
            {
                rra(a);
                init_idx_medium(*a);
            }
    }

    while(*b != cheapest->target)
    {
        if (cheapest->target->ab_medium == 1)
        {
                rb(b);
                init_idx_medium(*b);
        }
        else
            {
                rrb(b);
                init_idx_medium(*b);
            }
    }
    //PUSH B
    pb(a, b);
}

// void from_a_to_b(t_stack **a, t_stack **b)
// {
//     t_stack *info_a;
//     //ft_printf("estoy aquí");
    
//     info_a = *a;
//     //recupero info del cheapest y del objetivo
//     while(info_a && info_a->cheapest != 1)
//     { 
//         //ft_printf("nbr %i", info_a->nbr);
//         info_a = info_a->next;
//     }
//     //ft_printf("nbr %i", info_a->nbr);
//     //ft_printf("b %i", (*b)->nbr );

//     //ROTACIÓN AMBOS
//     //si tanto el cheapest como el target están por encima de la media, rotamos ambos
//     if (info_a->ab_medium == 1 && info_a->target->ab_medium == 1)
//     {
//         //ft_printf("estoy aquí primer if");
//         //comprobamos que no estén en índice 0, si están en índice cero no rotamos
//         while (*b != info_a->target && (info_a->idx!=0 || info_a->target->idx!=0))
//         {
// 		    rr(a, b);
//             init_idx_medium(*a);
//             init_idx_medium(*b);
//         }
//     }
//     else if (info_a->ab_medium == 0 && info_a->target->ab_medium == 0)
//     {
//         //ft_printf("estoy aquí segundo if");
//         //comprobamos que no estén en índice 0, si están en índice cero no rotamos
//         while (*b != info_a->target && (info_a->idx!=0 || info_a->target->idx!=0))
//         {
//             rrr(a, b);
//             init_idx_medium(*a);
//             init_idx_medium(*b);
//         }
//     }

//     if (info_a->target->ab_medium == 1)
//     {
//         //ft_printf("estoy aquí primer if");
//         //comprobamos que no estén en índice 0, si están en índice cero no rotamos
//         while (*b != info_a->target)
//         {
// 		    rb(b);
//             init_idx_medium(*b);
//         }
//     }
//     if (info_a->target->ab_medium == 0)
//     {
//         //ft_printf("estoy aquí segundo if");
//         //comprobamos que no estén en índice 0, si están en índice cero no rotamos
//         while (*b != info_a->target)
//         {
// 		    rrb(b);
//         //actualizamos el índice del elemento movido
//             init_idx_medium(*b);
//         }
//     }
//     //PUSH B
//     pb(a, b);

//     //imprimir_lista(*a);
//     //imprimir_lista(*b);

// }

void from_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *info_b;
    //ft_printf("estoy aquí");
    
    info_b = *b;
    //recupero info del cheapest y del objetivo
    // while(info_a && info_a->cheapest != 1)
    // { 
    //     ft_printf("nbr %i", info_a->nbr);
    //     info_a = info_a->next;
    // }
    // ft_printf("nbr %i", info_a->nbr);
    // ft_printf("b %i", (*b)->nbr );

    //ROTACIÓN AMBOS
    //si tanto el cheapest como el target están por encima de la media, rotamos ambos
    // if (info_b->ab_medium == 1 && info_b->target->ab_medium == 1)
    // {
    //     ft_printf("estoy aquí primer if");
    //     //comprobamos que no estén en índice 0, si están en índice cero no rotamos
    //     while (*b != info_a->target && (info_a->idx!=0 || info_a->target->idx!=0))
    //     {
	// 	    rr(a, b);
    //         init_idx_medium(*b);
    //     }
    // }
    // else if (info_a->ab_medium == 0 && info_a->target->ab_medium == 0)
    // {
    //     ft_printf("estoy aquí segundo if");
    //     //comprobamos que no estén en índice 0, si están en índice cero no rotamos
    //     while (*b != info_a->target && (info_a->idx!=0 || info_a->target->idx!=0))
    //     {
    //         rrr(a, b);
    //         init_idx_medium(*b);
    //     }
    // }

    if (info_b->target->ab_medium == 1)
    {
        //ft_printf("estoy aquí primer if");
        //comprobamos que no estén en índice 0, si están en índice cero no rotamos
        while (*a != info_b->target)
        {
		    ra(a);
            init_idx_medium(*a);
        }
    }
    if (info_b->target->ab_medium == 0)
    {
        //ft_printf("estoy aquí segundo if");
        //comprobamos que no estén en índice 0, si están en índice cero no rotamos
        while (*a != info_b->target)
        {
		    rra(a);
        //actualizamos el índice del elemento movido
            init_idx_medium(*a);
        }
    }
    //PUSH A
    pa(a, b);

    //imprimir_lista(*a);
    //imprimir_lista(*b);

}

void    reorder_a(t_stack **a)
{
    while ((*a)->nbr != min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (min(*a)->ab_medium) //Rotate or reverse rotate according to the position of the node on the median
			ra(a);
		else
			rra(a);
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
        len = stack_len(*a);
    }
    if (len > 3 && !is_sorted(*a))
    {
        //ft_printf("no está ordenado");
        pb(a, b);
        len = stack_len(*a);
    }
    while (len > 3)
    {
        init_data_ab(*a, *b);
        from_a_to_b(a,b);
        len = stack_len(*a);
    }
    sort_three(a);
    //pasamos los numeros de b a a, calculando el objetivo de b
    ft_printf("ESTOY AQUI");
    while(*b)
    {init_idx_medium(*a);
    init_idx_medium(*b);
    init_target_ba(*a, *b);
    //movemos los numeros de b a a 
    //esta vez no hacemos análisis de costes
    //pero asegurándonos que el objetivo de b está al principio
    //MEJORAR FROM_B_TO_A
    from_b_to_a(a,b);  
    }
    init_idx_medium(*a);
    //imprimir_lista_all(*a);
    reorder_a(a);
    
    //imprimir_lista_all(*a);
    //imprimir_lista_all(*b);

}