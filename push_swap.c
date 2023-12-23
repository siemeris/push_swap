/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/12/23 15:02:03 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//PUSH_SWAP DEBE ACEPTAR NEGATIVOS
//Si no se especifican parámetros, el programa no deberá mostrar nada y deberá
// devolver el control al usuario.

void leaks()
{
    system("leaks -q push_swap");
}

void imprimir_lista(t_stack *A)
{
    t_stack *aux;

    aux = A;
    while (aux)
    {
        ft_printf("%i", aux->nbr);
        aux = aux->next;
    }
    ft_printf("\n");
}

//para debuguear e imprimir todos los datos
void imprimir_lista_all(t_stack *A)
{
    t_stack *aux;

    aux = A;
    while (aux)
    {
        ft_printf("nbr:%i idx:%i cost:%i ab_medium:%i cheapest:%i\n", aux->nbr, aux->idx, aux->cost, aux->ab_medium, aux->cheapest);
        aux = aux->next;
    }
    ft_printf("\n");
}

void ft_lst_clear(t_stack *lst)
{
    t_stack *aux;

    if(!lst)
        return;
    while (lst)
    {
        aux = lst->next;
        free(lst);
        lst = aux;
    }
    lst = NULL;
}

int main(int argc, char *argv[])
{
    t_stack *A;
    t_stack *B;

    A = NULL;
    B = NULL;
    //atexit(leaks);
    int i;
    if (argc == 2 && argv[1][1] != '\0')
    {
        argv = ft_split(argv[1], ' ');
        //imprimimos la lista de argumentos
        i = 0;
        while(argv[i])
        {
            //ft_printf("argv %i %s", i, argv[i]);
            i++;
        }
        argc = i;
    }


    if (argc < 2)
    {
        //ft_printf("Error.\nNúmero de argumentos inválidos %i\n", argc);
        return(0);
    }
    else
    {
        //CORREGIR PARA QUE FUNCIONE CON ./push_swap "7 9 8" !!!!
        // ./push_swap --32 Debería dar error
        if (!check_arg(argc, argv))
            return (0);
        else
        {
            //ft_printf("numeros validos");

            //Creamos el stack A
            A = create_stack(argv, argc);
            
            if (is_sorted(A))
            {
                ft_lst_clear(A);
                return(0);
            }
        
            //ordenamos dos numeros
            //ft_printf("len:%i", stack_len(A));
            if (stack_len(A) == 2)
            {
                if (A->nbr > A->next->nbr)
                    sa(&A);
            }
            else if(stack_len(A) == 3)
            {   if (is_sorted(A))
                    return (0);
                else 
                    sort_three(&A);
            }
            else
                sort(&A, &B);
            
            //ft_printf("is_sorted:%i", is_sorted(A));
            //imprimir_lista(A);
            ft_lst_clear(A);
            //imprimir_lista(A);
            
        }
    }
    
    return(0);
}