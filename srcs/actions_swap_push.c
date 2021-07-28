/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:06:25 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/05/24 19:21:23 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stacks *strct, int print_sig)
{
	int	tmp_data;
	int	tmp_ind;

	if (strct->count_a <= 1)
		return ;
	tmp_data = strct->a->data;
	tmp_ind = strct->a->ind;
	strct->a->data = strct->a->next->data;
	strct->a->ind = strct->a->next->ind;
	strct->a->next->data = tmp_data;
	strct->a->next->ind = tmp_ind;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stacks *strct, int print_sig)
{
	int	tmp_data;
	int	tmp_ind;

	if (strct->count_b <= 1)
		return ;
	tmp_data = strct->b->data;
	tmp_ind = strct->b->ind;
	strct->b->data = strct->b->next->data;
	strct->b->ind = strct->b->next->ind;
	strct->b->next->data = tmp_data;
	strct->b->next->ind = tmp_ind;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("sb\n", 1);
	}
}

	/*if (strct->count_a <= 1 && strct->count_b <= 1)
	{
		ft_putstr_fd("Can't use SS. Can't swap both stacks.\n", 1);
		return ;
	}
	else if (strct->count_a <= 1)
	{
		ft_putstr_fd("Can't use SS. Can't swap stack a. Use SB command.\n", 1);
		return ;
	}
	else if (strct->count_b <= 1)
	{
		ft_putstr_fd("Can't use SS. Can't swap stack b. Use SA command.\n", 1);
		return ;
	}*/

void	ss(t_stacks *strct, int print_sig)
{
	sa(strct, 0);
	sb(strct, 0);
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("ss\n", 1);
	}
}

void	pa(t_stacks *strct, int print_sig)
{
	t_stack	*tmp;

	if (strct->count_b < 1)
		return ;
	tmp = strct->b;
	strct->b = strct->b->next;
	tmp->next = strct->a;
	strct->a = tmp;
	++strct->count_a;
	--strct->count_b;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stacks *strct, int print_sig)
{
	t_stack	*tmp;

	if (strct->count_a < 1)
		return ;
	tmp = strct->a;
	strct->a = strct->a->next;
	tmp->next = strct->b;
	strct->b = tmp;
	++strct->count_b;
	--strct->count_a;
	if (print_sig)
	{
		++strct->count_acts;
		ft_putstr_fd("pb\n", 1);
	}
}
