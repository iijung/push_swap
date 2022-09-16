/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/16 10:03:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_deque
{
	unsigned int	front;
	unsigned int	rear;
	unsigned int	max;
	int				*data;
}				t_deque;

t_deque	*deque_init(unsigned int max);
void	deque_clear(t_deque *dq);
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
