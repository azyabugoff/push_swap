/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:30:01 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 17:19:46 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_some_vals(int argc, t_stacks *strct)
{
	t_stack	*el;

	el = strct->a;
	while (el)
	{
		el->ind = 0;
		el->flag = 0;
		el = el->next;
	}
	strct->b = NULL;
	strct->count_b = 0;
	strct->count_a = argc - 1;
	strct->count_acts = 0;
	strct->nxt_ord = 1;
	strct->mid_ord = (strct->count_a - 1) / 2 + strct->nxt_ord;
	strct->max_ord = (strct->count_a);
	strct->flag = 0;
}

static int	init_a(t_stacks *strct, t_stack **elem, char **argv, int free_flag)
{
	*elem = (t_stack *)malloc(sizeof(t_stack));
	if (!(*elem))
	{
		if (free_flag)
			free_arr_push_swap(argv);
		return (ft_free_stack_err(&(strct->a), 0, "Malloc error.\n", 0));
	}
	strct->a = *elem;
	return (1);
}

int	init_stacks(int argc, char **argv, t_stacks *strct, int free_flag)
{
	int		i;
	t_stack	*elem;

	if (!init_a(strct, &elem, argv, free_flag))
		return (0);
	i = 0;
	while (++i < argc)
	{
		elem->data = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			elem->next = (t_stack *)malloc(sizeof(t_stack));
			if (!elem->next)
			{
				if (free_flag)
					free_arr_push_swap(argv);
				return (ft_free_stack_err(&(strct->a), 0, "Malloc error.\n", 1));
			}
			elem = elem->next;
		}
		else
			elem->next = NULL;
	}
	init_some_vals(argc, strct);
	return (1);
}

int	ft_free_stack_err(t_stack **stack, int ret, char *msg, int make_free)
{
	t_stack	*ptr;

	ptr = NULL;
	if (make_free)
	{
		if (stack && *stack)
		{
			while (stack && *stack)
			{
				ptr = (*stack)->next;
				(*stack)->next = NULL;
				free(*stack);
				*stack = ptr;
			}
		}
	}
	ft_putstr_fd(msg, 1);
	return (ret);
}
