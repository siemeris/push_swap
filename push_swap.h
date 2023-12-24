/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:46:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/24 14:27:43 by issierra         ###   ########.fr       */
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

int     check_arg(int argc, char **arg, int i);
t_stack *create_stack(char **argv, int argc, int i);

int     is_sorted(t_stack *lst);
int     stack_len(t_stack *lst);
void    sort_three(t_stack **lst);

//DEBUGUEAR
void    imprimir_lista(t_stack *A);
void    imprimir_lista_all(t_stack *A);

void    swap(t_stack **ptr);
void    rot(t_stack **ptr);
void    rotr(t_stack **ptr);
void    sa(t_stack **ptr);
void    sb(t_stack **ptr);
void    ss(t_stack **a, t_stack**b);
void    ra(t_stack **ptr);
void    rb(t_stack **ptr);
void    rr(t_stack **a, t_stack**b);
void    rrr(t_stack **a, t_stack**b);
void    rra(t_stack **ptr);
void    rrb(t_stack **ptr);
void    pb(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);

void    sort(t_stack **a, t_stack **b);

// void    upd_data_ab(t_stack *a, t_stack *b);
void    upd_idx_medium(t_stack *lst);
void    upd_target_ab(t_stack *a, t_stack *b);
void    upd_cost_ab(t_stack *a, t_stack *b);
void    upd_cheapest(t_stack *a);
void    upd_target_ba(t_stack *a, t_stack *b);

void    from_a_to_b(t_stack **a, t_stack **b);
void    from_b_to_a(t_stack **a, t_stack **b);

t_stack *max(t_stack *lst);
t_stack *min(t_stack *lst);
void    reorder_a(t_stack **a);

t_stack	*str_to_stack(char const *s, char c);

#endif