/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/11/30 11:14:37 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//PUSH_SWAP DEBE ACEPTAR NEGATIVOS

int check_arg(int argc, char **arg)
{
    int i;
    int j;
    int len;

    i = 1;
    j = i + 1;

    while(arg[i])
    {
        //comprobamos que sea numero
        len = ft_strlen(arg[i]);
        ft_printf("len %i", len );
        while(len >= 1)
        {
            // ft_printf("caracter %c", arg[i][len-1]);
            if (!(arg[i][len-1] >= 48 && arg[i][len-1] <= 57))
            {
                ft_printf("estoy awuí, caracter no valido %c", arg[i][len-1]);
                return(0);
            }
            len--; 
        }
        i++;
    }

    //comprobamos que no hay número repetidos
    i = 1;
    j = i + 1;
    ft_printf("i %i atoi %i", i, atoi(arg[j]));
    while (i < argc - 2)
    {
        while(arg[j])
        {
            if (atoi(arg[i])==atoi(arg[j]))
            {
                ft_printf("Números repes %i %i", atoi(arg[i]), atoi(arg[j]));
                return (0);
            }
            j++;
        }
        i++;
    }
    return(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        ft_printf("Error.\nNúmero de argumentos inválidos %i\n", argc);
        return(0);
    }
    else
    {
        //imprimo los argumentos
        int k = 0;
        while (k++ < argc)
            ft_printf("argv %s", argv[k]);
        if (!check_arg(argc, argv))
            return (0);
        else
            ft_printf("numeros validos");
    }
    
    return(0);
}