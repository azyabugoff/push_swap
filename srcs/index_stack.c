/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:32:59 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/27 01:02:37 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*list_to_arr(t_stacks *strct)
{
	t_stack	*el;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * (strct->count_a));
	if (!(arr))
	{
		ft_putstr_fd("Error.\nMalloc error.\n", 1);
		return (NULL);
	}
	el = strct->a;
	i = 0;
	while (el)
	{
		arr[i] = el->data;
		el = el->next;
		++i;
	}
	return (arr);
}

static void	put_indexes(t_stacks *strct, int *arr)
{
	t_stack	*el;
	int		i;

	el = strct->a;
	i = 1;
	while (el)
	{
		i = 1;
		while (i < strct->count_a + 1)
		{
			if (el->data == arr[i - 1])
				el->ind = i;
			++i;
		}
		el = el->next;
	}
}

int	index_stack(t_stacks *strct)
{
	int	*arr;

	arr = list_to_arr(strct);
	if (!arr)
		return (0);
	quick_sort(&arr, 0, strct->count_a - 1);
	put_indexes(strct, arr);
	free(arr);
	return (1);
}
