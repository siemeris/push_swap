/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/12/16 09:45:05 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leaks()
{
    system("leaks -q push_swap");
}

int push(char* arrA, char* arrB)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    while (arrA[i] != '\0')
        i++;
    while (arrB[j] != '\0')
        j++;
    temp = arrA[i - 1];
    arrA[i - 1] = arrB[j - 1];
    arrB[j - 1] = temp;
    return(0);
}

// int swap(char* arr)
// {
//     int temp;
    
//     temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//     return(0);
// }

int swap_a(char* arrA)
{
    int tmp;

    tmp = arrA[0];
    arrA[0] = arrA[1];
    arrA[1] = tmp;
    ft_printf("sa");
    return(0);
}

int swap_b(char* arrB)
{
    int tmp;

    tmp = arrB[0];
    arrB[0] = arrB[1];
    arrB[1] = tmp;
    ft_printf("sb");
    return(0);
}

//PUSH_SWAP DEBE ACEPTAR NEGATIVOS

int *ft_bubble_sort(int *arr, int n)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < n - 1)
    {
        j = 0;
        while (j < n - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                //swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ft_printf("s %i %i", arr[j], arr[j + 1]);
            }
            j++;
        }
        i++;
    }

    return (arr);
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
}

t_stack *ft_lst_new(int nbr)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->nbr = nbr;
    new->next = NULL;
    return (new);
}

void create_stack(t_stack *A, char **argv, int argc)
{
    int i;
    t_stack *aux;

    i = 1;
    A = ft_lst_new(ft_atoi(argv[i]));
    aux = A;
    i++;
    while (i < argc)
    {
        aux->next = ft_lst_new(ft_atoi(argv[i]));
        i++;
        aux = aux->next;
    }
    aux->next = NULL;

    imprimir_lista(A);
}


int main(int argc, char *argv[])
{
    t_stack *A;

    A = NULL;
    //atexit(leaks);
    if (argc < 2)
    {
        ft_printf("Error.\nNúmero de argumentos inválidos %i\n", argc);
        return(0);
    }
    else
    {
        if (!check_arg(argc, argv))
            return (0);
        else
        {
            ft_printf("numeros validos");

            //Creamos el stack A
            create_stack(A, argv, argc);

        }
    }
    
    return(0);
}