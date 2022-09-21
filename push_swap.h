/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/21 19:07:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack 		t_stack;
typedef struct s_data		t_data;

struct s_stack
{
	int		cnt;
	t_list	*front;
	t_list	*rear;
	int		(*pop)(struct s_stack *, int *, int);
	int		(*push)(struct s_stack *, int, int);
	int		(*swap)(struct s_stack *);
	int		(*rotate)(struct s_stack *, int);
};

struct s_data
{
	t_stack	a;
	t_stack	b;
};

int	stack_init(t_stack *st);
int	data_parse(t_data *data, int size, char **strs);
#endif
