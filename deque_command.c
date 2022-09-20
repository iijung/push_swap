/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:03:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/20 21:32:48 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_swap(t_deque *dq)
{
	int	num;

	if (dq == 0)
		return (-1);
	if (deque_count(dq) < 2)
		return (0);
	num = dq->data[(dq->front + 1) % dq->max];
	dq->data[(dq->front + 1) % dq->max] = dq->data[(dq->front + 2) % dq->max];
	dq->data[(dq->front + 2) % dq->max] = num;
	return (0);
}

int	deque_push(t_deque *get, t_deque *put)
{
	if (get == 0 || put == 0)
		return (-1);
	if (deque_empty(get))
		return (0);
	return (deque_push_front(put, deque_pop_front(get)));
}

int	deque_rotate(t_deque *dq)
{
	int	tmp;

	if (dq == 0)
		return (-1);
	if (deque_empty(dq))
		return (0);
	tmp = deque_pop_front(dq);
	return (deque_push_rear(dq, tmp));
}

int	deque_rrotate(t_deque *dq)
{
	int	tmp;

	if (dq == 0)
		return (-1);
	if (deque_empty(dq))
		return (0);
	tmp = deque_pop_rear(dq);
	return (deque_push_front(dq, tmp));
}
