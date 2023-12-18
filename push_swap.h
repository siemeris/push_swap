/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:46:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/18 15:54:54 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
    int    nbr;
    int    pos;
    struct s_stack *next;
}	t_stack;

int check_arg(int argc, char **arg);
t_stack *create_stack(char **argv, int argc);


#endif