/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:08:45 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 20:00:41 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/**/
void	print_stack(t_stacks *strct, t_stack *st, int count_els, int count_acts)
{
	t_stack	*el;

	el = st;
	if (st == strct->a)
		ft_putstr_fd("-----------------------\nStack A:\n", 1);
	else if (st == strct->b)
		ft_putstr_fd("-----------------------\nStack B:\n", 1);
	else
		ft_putstr_fd("Some stack:\n", 1);
	ft_putstr_fd("count_els = ", 1);
	ft_putnbr_fd(count_els, 1);
	ft_putstr_fd("\n", 1);
	while (el != NULL)
	{
		ft_putnbr_fd(el->data, 1);
		ft_putstr_fd(" ", 1);
		el = el->next;
	}
	if (!is_sorted_stack(st))
		ft_putstr_fd("\nNot sorted after all.\n", 1);
	else
		ft_putstr_fd("\nSorted.\n", 1);
	ft_putstr_fd("count_acts = ", 1);
	ft_putnbr_fd(count_acts, 1);
	ft_putstr_fd("\n-----------------------\n", 1);
}
/**/

void	free_arr_push_swap(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		++i;
	}
	if (arr)
		free(arr);
}

int	handle_one_arg(char **argv, int *cnt, char ***arr)
{
	char	*str;
	int		space_flag;

	if (argv[1][0] == '\0')
		return (0);
	space_flag = 1;
	while (argv[1][(*cnt)])
	{
		if (argv[1][(*cnt)++] != ' ')
			space_flag = 0;
	}
	if (space_flag)
		return (0);
	*cnt = 0;
	str = ft_strjoin("./push_swap ", argv[1]);
	if (!str)
	{
		ft_putstr_fd("Error.\nMalloc error.\n", 1);
		return (0);
	}
	*arr = ft_split(str, ' ');
	free(str);
	while (*arr && (*arr)[(*cnt)])
		++(*cnt);
	return (1);
}

static int	check_init_one_arg(char **argv, char ***arr, t_stacks *strct)
{
	int		cnt;

	cnt = 0;
	if (!handle_one_arg(argv, &cnt, arr))
		return (0);
	if (!valid_args(cnt, *arr))
		return (0);
	if (!init_stacks(cnt, *arr, strct, 1))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	strct;
	char		**arr;

	arr = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (!check_init_one_arg(argv, &arr, &strct))
			return (0);
	}
	else
	{
		if (!valid_args(argc, argv))
			return (0);
		if (!init_stacks(argc, argv, &strct, 0))
			return (0);
	}
	if (!push_swap(&strct))
		return (0);
	ft_free_stack_err(&(strct.a), 0, "", 1);
	ft_free_stack_err(&(strct.b), 0, "", 1);
	free_arr_push_swap(arr);
	return (0);
}

/*
print_stack(&strct, strct.a, strct.count_a, strct.count_acts);
print_stack(&strct, strct.b, strct.count_b, strct.count_acts);
*/
