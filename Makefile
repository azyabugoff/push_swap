# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 18:33:46 by sesnowbi          #+#    #+#              #
#    Updated: 2021/06/03 00:00:43 by sesnowbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT_D	= ./libft
LIBFT_A	= libft.a
LIBFT_H = libft.h
LIBFT	= libft/libft.a

SRCS	= main.c srcs/valid_args.c srcs/valid_args_utils.c srcs/init_free_stacks.c \
			srcs/actions_swap_push.c srcs/actions_rotate.c srcs/actions_rev_rotate.c \
			srcs/push_swap.c srcs/sort_little_numbers.c srcs/index_stack.c srcs/quick_sort.c \
			srcs/sort_big_numbers.c srcs/sort_6_numbers.c srcs/global_alg_moves.c srcs/global_alg_utils.c
INC		= includes/push_swap.h 
DEPS	= $(INC) $(LIBFT_D)/$(LIBFT_H)
OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= /bin/rm -f
CFLAGS	= -g -Wall -Werror -Wextra# -fsanitize=address
FLAGS	= -g -Llibft -lft -Wall -Werror -Wextra# -fsanitize=address

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -include $(INC) -o $(<:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

$(LIBFT) :	NONE
				$(MAKE) -C $(LIBFT_D)

clean:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(LIBFT_D)

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(LIBFT_A)
					$(MAKE) fclean -C $(LIBFT_D)

re:				fclean all

.PHONY:			all clean fclean re NONE
