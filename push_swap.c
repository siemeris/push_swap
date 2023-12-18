/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/12/18 18:16:20 by issierra         ###   ########.fr       */
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

void swap_a(t_stack *ptr)
{
    int tmp;

    tmp = ptr->nbr;
    ptr->nbr = ptr->next->nbr;
    ptr->next->nbr = tmp;
    ft_printf("sa");
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



// void del(void *content)
// {
//     free(content);
// }


// void ft_lst_delone(t_stack *lst, void (*del)(void *))
// {
//     if (!lst)
//         return;
//     del(&lst->nbr);
//     del(&lst->pos);
//     free(lst);
// }


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

// void	free_stack(t_stack *head)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		temp = current->next;
// 		free(current);
// 		current = temp;
// 	}
// }

int main(int argc, char *argv[])
{
    t_stack *A;

    A = NULL;
    atexit(leaks);
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
            A = create_stack(argv, argc);
            //al terminar programa liberamos memoria
        
            //ordenamos dos numeros
            if (argc == 3)
            {
                if (A->nbr > A->next->nbr)
                {
                    swap_a(A);
                    ft_printf("print desp del swap: %i %i", A->nbr, A->next->nbr);

                    ft_printf("\n");
                }
            }
            imprimir_lista(A);
            ft_lst_clear(A);
            //free_stack(A);
            
            //imprimir_lista(A);
            
        }
    }
    
    return(0);
}