/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/21 11:59:35 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack 		t_stack;
typedef struct s_data		t_data;

struct s_stack
{
	int		front;
	int		rear;
	int		cnt;
	int		max;
	int		*arr;
	t_stack	*(*pop)(struct s_stack *, int *, int);
	t_stack	*(*push)(struct s_stack *, int, int);
	t_stack	*(*swap)(struct s_stack *);
	t_stack	*(*rotate)(struct s_stack *, int);
};

struct s_data
{
	int		max;
	int		*arr;
	t_stack	a;
	t_stack	b;
};

int	stack_init(t_stack *st, int max);
#endif
