/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/20 19:44:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_deque
{
	int	front;
	int	rear;
	int	max;
	int	*data;
}				t_deque;

typedef struct s_push_swap
{
	int			size;
	int			*arr;
	t_deque		a;
	t_deque		b;
}				t_push_swap;

int		deque_init(t_deque *dq, int max);
void	deque_begin(t_deque *dq);
void	deque_end(t_deque *dq);

int		deque_full(t_deque *dq);
int		deque_empty(t_deque *dq);
int		deque_front(t_deque *dq);
int		deque_rear(t_deque *dq);

int		deque_push_rear(t_deque *dq, int n);
int		deque_push_front(t_deque *dq, int n);
int		deque_pop_rear(t_deque *dq);
int		deque_pop_front(t_deque *dq);
#endif
