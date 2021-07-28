/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:40:53 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/30 17:00:38 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	pb_pa_els_no_flags(t_stacks *strct)
{
	pb_little_half(strct, strct->count_a);
	recount_vars(strct, 1);
	while (strct->count_b > 3)
	{
		sort_next(strct, 0);
		pa_big_half(strct, strct->count_b, 1);
		recount_vars(strct, 1);
		if (strct->count_b == 0 && is_sorted_stack(strct->a))
			return (0);
	}
	if (strct->count_b <= 3 && strct->count_b > 0)
		pa_3_or_less(strct, strct->count_b);
	return (1);
}

static int	pb_pa_els_with_flags(t_stacks *strct, int *flag_val)
{
	*flag_val = strct->a->flag;
	while (strct->a->flag == *flag_val || strct->count_b > 0)
	{
		while (strct->a->flag == *flag_val && strct->a->flag != 0)
		{
			sort_next(strct, 0);
			pb(strct, 1);
		}
		find_stack_max(strct, strct->b, 0);
		strct->mid_ord = (strct->max_ord - strct->nxt_ord) / 2
			+ strct->nxt_ord;
		while (strct->count_b > 0)
		{
			sort_next(strct, 0);
			pa_big_half(strct, strct->count_b, 0);
			recount_vars(strct, 0);
			if (strct->count_b == 0 && is_sorted_stack(strct->a))
				return (0);
		}
		if (strct->count_b == 0 && is_sorted_stack(strct->a))
			return (0);
	}
	return (1);
}

static int	pb_pa_els_no_flags2(t_stacks *strct, int *count_rot)
{
	find_stack_max(strct, strct->a, 1);
	strct->mid_ord = (strct->max_ord - strct->nxt_ord) / 2
		+ strct->nxt_ord;
	sort_next(strct, 0);
	pb_half_unsorted(strct, count_rot);
	sort_next(strct, 0);
	while ((*count_rot)--)
	{
		if (strct->b->ind != strct->nxt_ord)
			rrr(strct, 1);
		else
			rra(strct, 1);
	}
	*count_rot = 0;
	recount_vars(strct, 1);
	while (strct->count_b > 0)
	{
		pa_big_half(strct, strct->count_b, 1);
		recount_vars(strct, 1);
		if (strct->count_b == 0 && is_sorted_stack(strct->a))
			return (0);
	}
	return (1);
}

void	global_algorithm(t_stacks *strct)
{
	int	flag_val;
	int	count_rot;

	count_rot = 0;
	if (!pb_pa_els_no_flags(strct))
		return ;
	flag_val = strct->a->flag;
	while (strct->a->flag != 0)
		if (!pb_pa_els_with_flags(strct, &flag_val))
			return ;
	while (!is_sorted_stack(strct->a))
	{
		if (!pb_pa_els_no_flags2(strct, &count_rot))
			return ;
		flag_val = strct->a->flag;
		while (strct->a->flag != 0)
			if (!pb_pa_els_with_flags(strct, &flag_val))
				return ;
	}
}

int	sort_big(t_stacks *strct)
{
	if (!index_stack(strct))
		return (0);
	if (strct->count_a == 6)
		sort_6_numbers(strct);
	else
		global_algorithm(strct);
	return (1);
}
