/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:23:40 by issierra          #+#    #+#             */
/*   Updated: 2023/12/26 09:13:13 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int			count;
	int			ini_word;
	char const	*temp;

	temp = s;
	count = 0;
	ini_word = 0;
	while (*temp)
	{
		if (*temp != c)
			ini_word = 1;
		if (*temp == c && ini_word == 1)
		{
			count++;
			ini_word = 0;
		}
		temp++;
	}
	if (ini_word == 1)
		count++;
	return (count);
}

static int	ft_len_word(char const *s, char c)
{
	char const	*temp;
	int			len;

	temp = s;
	len = 0;
	while (*temp != c && *temp != '\0')
	{
		len++;
		temp++;
	}
	return (len);
}

static char	**ft_free(char **res, int w)
{
	while (w >= 0)
	{
		free(res[w]);
		w--;
	}
	free(res);
	return (NULL);
}

static char	**ft_copy(char const *s, char c, char **res, int num_words)
{
	int		w;
	int		l;

	w = 0;
	while (w < num_words)
	{
		l = 0;
		while (*s == c)
			s++;
		res[w] = malloc(sizeof(char) * (ft_len_word(s, c) + 1));
		if (!res[w])
		{
			ft_free(res, w);
			return (NULL);
		}
		while (*s != c && *s != '\0')
		{
			res[w][l++] = *s;
			s++;
		}
		res[w++][l] = '\0';
	}
	res[w] = NULL;
	return (res);
}

t_stack	*str_to_stack(char const *s, char c)
{
	char	**res;
	int		num_words;
	int		i;
	int		resc;
	t_stack	*a;

	num_words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (num_words + 2));
	if (!res || !s)
		return (NULL);
	res = ft_copy(s, c, res, num_words);
	i = 0;
	while (res[i])
		i++;
	resc = i;
	if (!check_arg(resc, res, 0))
	{
		ft_free(res, resc);
		return (0);
	}
	a = create_stack(res, resc, 0);
	ft_free(res, resc);
	return (a);
}
