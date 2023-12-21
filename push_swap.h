/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:46:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/21 17:55:00 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
    int     nbr;
    int     idx;
    int     cost;
    int     ab_medium;
    int     cheapest;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
}	t_stack;

int     check_arg(int argc, char **arg);
t_stack *create_stack(char **argv, int argc);
void    rot(t_stack **ptr);
void    rotr(t_stack **ptr);
int     is_sorted(t_stack *lst);
int     stack_len(t_stack *lst);
void    sort_three(t_stack **lst);
void    imprimir_lista(t_stack *A);
void    swap(t_stack **ptr);
void    sa(t_stack **ptr);
void    sb(t_stack **ptr);
void    ss(t_stack **a, t_stack**b);
void    ra(t_stack **ptr);
void    rb(t_stack **ptr);
void    rr(t_stack **a, t_stack**b);
void    rrr(t_stack **a, t_stack**b);
void    rra(t_stack **ptr);
void    rrb(t_stack **ptr);
void    sort(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);

void    init_data_ab(t_stack *a, t_stack *b);
void    init_idx_medium(t_stack *lst);
void    init_target_ab(t_stack *a, t_stack *b);
void    init_cost_ab(t_stack *a, t_stack *b);
// void    init_cheapest(t_stack *a);

#endif