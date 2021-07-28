/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_alg_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 22:11:56 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/29 22:13:09 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_next(t_stacks *strct, int sort_next_b_sig)
{
	while (strct->a->ind == strct->nxt_ord)
	{
		ra(strct, 1);
		++strct->nxt_ord;
	}
	if (sort_next_b_sig)
	{
		while (strct->b->ind == strct->nxt_ord)
		{
			pa(strct, 1);
			ra(strct, 1);
			++strct->nxt_ord;
		}
	}
}

void	sort_b_3_els(t_stacks *strct)
{
	t_stack	*el;

	el = strct->b;
	if (el->data > el->next->data && el->data < el->next->next->data
		&& el->next->data < el->next->next->data)
		sb(strct, 1);
	else if (el->data > el->next->data && el->data > el->next->next->data
		&& el->next->data > el->next->next->data)
	{
		sb(strct, 1);
		rrb(strct, 1);
	}
	else if (el->data > el->next->data && el->data > el->next->next->data
		&& el->next->data < el->next->next->data)
		rb(strct, 1);
	else if (el->data < el->next->data && el->data < el->next->next->data
		&& el->next->data > el->next->next->data)
	{
		sb(strct, 1);
		rb(strct, 1);
	}
	else if (el->data < el->next->data && el->data > el->next->next->data
		&& el->next->data > el->next->next->data)
		rrb(strct, 1);
}

void	recount_vars(t_stacks *strct, int iter_flag_sig)
{
	strct->max_ord = strct->mid_ord;
	strct->mid_ord = (strct->max_ord - strct->nxt_ord) / 2 + strct->nxt_ord;
	if (iter_flag_sig)
		++strct->flag;
}

void	find_stack_max(t_stacks *strct, t_stack *st, int unsorted_sig)
{
	t_stack	*el;
	int		max_ind;

	el = st;
	max_ind = 0;
	if (unsorted_sig)
	{
		while (el && el->flag == 0)
		{
			if (el->ind >= max_ind)
				max_ind = el->ind;
			el = el->next;
		}
	}
	else
	{
		while (el)
		{
			if (el->ind >= max_ind)
				max_ind = el->ind;
			el = el->next;
		}
	}
	strct->max_ord = max_ind;
}
