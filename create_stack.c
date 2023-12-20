#include "push_swap.h"

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

int is_sorted(t_stack *lst)
{
    t_stack *aux;

    aux = lst;
    while(aux->next)
    {
        if (aux->nbr > aux->next->nbr)
            return (0);
        aux = aux->next;
    }
    return (1);
}

int stack_len(t_stack *lst)
{
    t_stack *aux;
    int len;

    aux = lst;
    len = 0;
    while(aux)
    {
        len++;
        aux = aux->next;
    }
    return (len);
}


t_stack *create_stack(char **argv, int argc)
{
    int i;
    t_stack *aux;
	t_stack *A;

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

	return (A);
}
