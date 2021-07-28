/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:13:18 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 23:59:51 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	partition(int **arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = (*arr)[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if ((*arr)[j] <= pivot)
		{
			++i;
			tmp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = tmp;
		}
		++j;
	}
	tmp = (*arr)[i + 1];
	(*arr)[i + 1] = (*arr)[end];
	(*arr)[end] = tmp;
	return (i + 1);
}

void	quick_sort(int **arr, int start, int end)
{
	int	part;

	if (start < end)
	{
		part = partition(arr, start, end);
		quick_sort(arr, start, part - 1);
		quick_sort(arr, part + 1, end);
	}
}
