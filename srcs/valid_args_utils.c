/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:54:05 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 17:27:48 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_num(char c, int ind)
{
	if (ind == 0)
	{
		if ((c < '0' || c > '9') && c != '-')
		{
			ft_putstr_fd("Error.\nNot valid arguments.\n", 1);
			return (0);
		}
	}
	else
	{
		if (c < '0' || c > '9')
		{
			ft_putstr_fd("Error.\nNot valid arguments.\n", 1);
			return (0);
		}
	}
	return (1);
}

int	has_duplicates(int argc, char **argv, int i)
{
	int	cur;
	int	len1;
	int	len2;

	cur = i;
	len1 = ft_strlen(argv[cur]);
	len2 = 0;
	while (++i < argc)
	{
		len2 = ft_strlen(argv[i]);
		if (ft_strncmp(argv[cur], argv[i],
				ft_tern_i((len1 >= len2), len1, len2)) == 0)
		{
			ft_putstr_fd("Error.\nArguments have duplicates.\n", 1);
			return (1);
		}
	}
	return (0);
}

int	is_int(char *str)
{
	char	*cmp;
	int		len1;
	int		len2;

	cmp = ft_itoa(ft_atoi(str));
	if (!cmp)
	{
		ft_putstr_fd("Error.\nMalloc error.\n", 1);
		return (0);
	}
	len1 = ft_strlen(cmp);
	len2 = ft_strlen(str);
	if (ft_strncmp(cmp, str, ft_tern_i((len1 >= len2), len1, len2)))
	{
		ft_putstr_fd("Error.\nNot all arguments are integers.\n", 1);
		free(cmp);
		return (0);
	}
	free(cmp);
	return (1);
}
