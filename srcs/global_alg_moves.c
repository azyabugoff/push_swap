/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_alg_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 22:07:55 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/30 00:07:09 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_ra_cicle(t_stacks *strct, int count)
{
	while (count > 0)
	{
		pa(strct, 1);
		ra(strct, 1);
		++strct->nxt_ord;
		--count;
	}
}

void	pa_3_or_less(t_stacks *strct, int count_b)
{
	if (is_sorted_stack(strct->b))
		pa_ra_cicle(strct, count_b);
	else if (count_b == 2)
	{
		sb(strct, 1);
		pa_ra_cicle(strct, 2);
	}
	else if (count_b == 3)
	{
		sort_b_3_els(strct);
		pa_ra_cicle(strct, 3);
	}
}

void	pb_little_half(t_stacks *strct, int count)
{
	while (count--)
	{
		if (strct->a->ind <= strct->mid_ord)
			pb(strct, 1);
		else
		{
			sort_next(strct, 0);
			ra(strct, 1);
		}
	}
}

void	pa_big_half(t_stacks *strct, int count, int put_flag)
{
	while (count--)
	{
		if (strct->b->ind >= strct->mid_ord || strct->b->ind == strct->nxt_ord)
		{
			sort_next(strct, 0);
			pa(strct, 1);
			if (put_flag)
				strct->a->flag = strct->flag;
			sort_next(strct, 0);
		}
		else
			rb(strct, 1);
	}
}

void	pb_half_unsorted(t_stacks *strct, int *count_rot)
{
	while (strct->a->flag == 0)
	{
		if (strct->a->ind <= strct->mid_ord)
			pb(strct, 1);
		else
		{
			ra(strct, 1);
			++(*count_rot);
		}
	}
}
