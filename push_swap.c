/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/12/20 18:47:04 by issierra         ###   ########.fr       */
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
    //t_stack *B;

    A = NULL;
    //B = NULL;
    //atexit(leaks);
    if (argc < 2)
    {
        //ft_printf("Error.\nNúmero de argumentos inválidos %i\n", argc);
        return(0);
    }
    else
    {
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
                {
                    sa(A);
                    //ft_printf("print desp del swap: %i %i", A->nbr, A->next->nbr);

                    //ft_printf("\n");
                }
            }
            else if(stack_len(A) == 3)
            {   if (is_sorted(A))
                    return (0);
                else 
                    sort_three(&A);
            }
            
            //ft_printf("is_sorted:%i", is_sorted(A));
            //imprimir_lista(A);
            ft_lst_clear(A);
            //free_stack(A);
            //imprimir_lista(A);
            
        }
    }
    
    return(0);
}