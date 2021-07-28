/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:30:12 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/30 17:14:38 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_3_els(t_stacks *strct)
{
	t_stack	*el;

	el = strct->a;
	if (el->data > el->next->data && el->data < el->next->next->data
		&& el->next->data < el->next->next->data)
		sa(strct, 1);
	else if (el->data > el->next->data && el->data > el->next->next->data
		&& el->next->data > el->next->next->data)
	{
		sa(strct, 1);
		rra(strct, 1);
	}
	else if (el->data > el->next->data && el->data > el->next->next->data
		&& el->next->data < el->next->next->data)
		ra(strct, 1);
	else if (el->data < el->next->data && el->data < el->next->next->data
		&& el->next->data > el->next->next->data)
	{
		sa(strct, 1);
		ra(strct, 1);
	}
	else if (el->data < el->next->data && el->data > el->next->next->data
		&& el->next->data > el->next->next->data)
		rra(strct, 1);
	return (1);
}

static void	cases_for_sort_4(t_stacks *strct, t_stack *el, int i, int check_ind)
{
	if (el->ind == check_ind && i == 1)
		pb(strct, 1);
	else if (el->ind == check_ind && i == 2)
	{
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == check_ind && i == 3)
	{
		ra(strct, 1);
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == check_ind && i == 4)
	{
		rra(strct, 1);
		pb(strct, 1);
	}
}

int	sort_4_els(t_stacks *strct, int check_ind)
{
	t_stack	*el;
	int		i;

	el = strct->a;
	i = 1;
	while (el)
	{
		cases_for_sort_4(strct, el, i, check_ind);
		el = el->next;
		++i;
	}
	sort_3_els(strct);
	pa(strct, 1);
	return (1);
}

static void	cases_for_sort_5(t_stacks *strct, t_stack *el, int i, int check_ind)
{
	if (el->ind == check_ind && i == 1)
		pb(strct, 1);
	else if (el->ind == check_ind && i == 2)
	{
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == check_ind && i == 3)
	{
		ra(strct, 1);
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == check_ind && i == 4)
	{
		rra(strct, 1);
		rra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == check_ind && i == 5)
	{
		rra(strct, 1);
		pb(strct, 1);
	}
}

int	sort_5_els(t_stacks *strct, int check_ind)
{
	t_stack	*el;
	int		i;

	el = strct->a;
	i = 1;
	while (el)
	{
		cases_for_sort_5(strct, el, i, check_ind);
		el = el->next;
		++i;
	}
	sort_4_els(strct, check_ind + 1);
	pa(strct, 1);
	return (1);
}
