/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:24:24 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 22:46:56 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *strct, int print_sig)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (strct->count_a <= 1)
		return ;
	tmp = strct->a;
	tmp1 = strct->a;
	while (strct->a->next)
		strct->a = strct->a->next;
	while (tmp1->next != strct->a)
		tmp1 = tmp1->next;
	strct->a->next = tmp;
	tmp1->next = NULL;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stacks *strct, int print_sig)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (strct->count_b <= 1)
		return ;
	tmp = strct->b;
	tmp1 = strct->b;
	while (strct->b->next)
		strct->b = strct->b->next;
	while (tmp1->next != strct->b)
		tmp1 = tmp1->next;
	strct->b->next = tmp;
	tmp1->next = NULL;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stacks *strct, int print_sig)
{
	rra(strct, 0);
	rrb(strct, 0);
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("rrr\n", 1);
	}
}
