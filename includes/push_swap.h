/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:45 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/06/02 23:58:51 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				ind;
	int				flag;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int		count_a;
	int		count_b;
	int		flag;
	int		count_acts;
	t_stack	*a;
	t_stack	*b;
	int		nxt_ord;
	int		mid_ord;
	int		max_ord;
}	t_stacks;

int				valid_args(int argc, char **argv);
void			free_arr_push_swap(char **arr);
int				handle_one_arg(char **argv, int *cnt, char ***arr);
int				handle_several_args(int argc, char **argv, int i, int j);
int				is_valid_num(char c, int ind);
int				has_duplicates(int argc, char **argv, int i);
int				is_int(char *str);
int				init_stacks(int argc, char **argv,
					t_stacks *strct, int free_flag);
void			print_stack(t_stacks *strct, t_stack *st,
					int count_els, int count_acts);
int				ft_free_stack_err(t_stack **stack,
					int ret, char *msg, int make_free);
void			sa(t_stacks *strct, int print_sig);
void			sb(t_stacks *strct, int print_sig);
void			ss(t_stacks *strct, int print_sig);
void			pa(t_stacks *strct, int print_sig);
void			pb(t_stacks *strct, int print_sig);
void			ra(t_stacks *strct, int print_sig);
void			rb(t_stacks *strct, int print_sig);
void			rr(t_stacks *strct, int print_sig);
void			rra(t_stacks *strct, int print_sig);
void			rrb(t_stacks *strct, int print_sig);
void			rrr(t_stacks *strct, int print_sig);
int				push_swap(t_stacks *strct);
int				is_sorted_stack(t_stack *st);
int				sort_3_els(t_stacks *strct);
int				sort_4_els(t_stacks *strct, int check_ind);
int				sort_5_els(t_stacks *strct, int check_ind);
void			sort_6_numbers(t_stacks *strct);
int				sort_little(t_stacks *strct);
int				index_stack(t_stacks *strct);
void			quick_sort(int **arr, int start, int end);
int				sort_big(t_stacks *strct);
void			global_algorithm(t_stacks *strct);
void			pb_little_half(t_stacks *strct, int count);
void			recount_vars(t_stacks *strct, int iter_flag_sig);
void			pa_big_half(t_stacks *strct, int count, int put_flag);
void			sort_next(t_stacks *strct, int sort_next_b_sig);
void			find_stack_max(t_stacks *strct, t_stack *st, int unsorted_sig);
void			pb_half_unsorted(t_stacks *strct, int *count_rot);
void			sort_b_3_els(t_stacks *strct);
void			pa_3_or_less(t_stacks *strct, int count_b);

#endif
