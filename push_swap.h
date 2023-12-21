/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:46:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/21 10:05:35 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
    int    nbr;
    int    idx;
    struct s_stack *next;
    struct s_stack *prev;
}	t_stack;

int     check_arg(int argc, char **arg);
t_stack *create_stack(char **argv, int argc);
void    sa1(t_stack *ptr);
void    rot(t_stack **ptr);
void    rotr(t_stack **ptr);
int     is_sorted(t_stack *lst);
int     stack_len(t_stack *lst);
void    sort_three(t_stack **lst);
void    imprimir_lista(t_stack *A);
void    swap(t_stack **ptr);
void    sa(t_stack **ptr);
void    sb(t_stack **ptr);
void    ra(t_stack **ptr);
void    rb(t_stack **ptr);
void    rra(t_stack **ptr);
void    rrb(t_stack **ptr);

#endif