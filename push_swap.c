/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:52:57 by issierra          #+#    #+#             */
/*   Updated: 2023/12/25 09:12:53 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_clear(t_stack *lst)
{
	t_stack	*aux;

	if (!lst)
		return ;
	while (lst)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
	lst = NULL;
}

int	sort_cases(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(*a))
		return (0);
	if (stack_len(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	else if (stack_len(*a) == 3)
	{
		if (is_sorted(*a))
			return (0);
		else
			sort_three(a);
	}
	else
		sort(a, &b);
	return (1);
}

void	free_split(char **split)
{
	if (split == NULL || *split == NULL)
		return ;
	ft_printf("freeing split\n %s", split[1]);
	free(split[0]);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		a = str_to_stack(argv[1], ' ');
		if (!a)
			return (0);
	}
	else
	{
		if (!check_arg(argc, argv, 1))
			return (0);
		a = create_stack(argv, argc, 1);
	}
	if (!sort_cases(&a))
	{
		ft_lst_clear(a);
		return (0);
	}
	ft_lst_clear(a);
	return (0);
}
