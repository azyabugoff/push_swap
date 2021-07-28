/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:45:05 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/30 17:03:52 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	from_1_to_3(t_stacks *strct, t_stack *el, int i)
{
	if (el->ind == 1 && i == 1)
		pb(strct, 1);
	else if (el->ind == 1 && i == 2)
	{
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == 1 && i == 3)
	{
		ra(strct, 1);
		ra(strct, 1);
		pb(strct, 1);
	}
}

static void	from_4_to_6(t_stacks *strct, t_stack *el, int i)
{
	if (el->ind == 1 && i == 4)
	{
		ra(strct, 1);
		ra(strct, 1);
		ra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == 1 && i == 5)
	{
		rra(strct, 1);
		rra(strct, 1);
		pb(strct, 1);
	}
	else if (el->ind == 1 && i == 6)
	{
		rra(strct, 1);
		pb(strct, 1);
	}
}

static void	cases_for_sort_6(t_stacks *strct, t_stack *el, int i)
{
	if (el->ind == 1 && i >= 1 && i <= 3)
		from_1_to_3(strct, el, i);
	else if (el->ind == 1 && i >= 4 && i <= 6)
		from_4_to_6(strct, el, i);
}

void	sort_6_numbers(t_stacks *strct)
{
	t_stack	*el;
	int		i;

	el = strct->a;
	i = 1;
	while (el)
	{
		cases_for_sort_6(strct, el, i);
		el = el->next;
		++i;
	}
	sort_5_els(strct, 2);
	pa(strct, 1);
}
