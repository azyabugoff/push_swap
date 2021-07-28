/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:59:12 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 20:09:01 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_several_args(int argc, char **argv, int i, int j)
{
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' && !argv[i][j + 1])
				|| (argv[i][j] == '-' && argv[i][j + 1] == '0'))
			{
				ft_putstr_fd("Error.\nNot valid arguments.\n", 1);
				return (0);
			}
			if (!is_valid_num(argv[i][j], j) || has_duplicates(argc, argv, i))
				return (0);
		}
		if (!is_int(argv[i]))
			return (0);
	}
	return (1);
}

int	valid_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!handle_several_args(argc, argv, i, j))
		return (0);
	return (1);
}
