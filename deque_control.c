/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:52:27 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/16 09:53:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_push_rear(t_deque *dq, int n)
{
	if (deque_full(dq) != 0)
		return (-1);
	dq->rear = (dq->rear + 1) % dq->max;
	dq->data[dq->rear] = n;
	return (0);
}

int	deque_push_front(t_deque *dq, int n)
{
	if (deque_full(dq) != 0)
		return (-1);
	dq->data[dq->front] = n;
	dq->front = (dq->front - 1 + dq->max) % dq->max;
	return (0);
}

int	deque_pop_rear(t_deque *dq)
{
	if (deque_empty(dq) != 0)
		return (-1);
	dq->rear = (dq->rear - 1 + dq->max) % dq->max;
	return (dq->data[(dq->rear + 1) % dq->max]);
}

int	deque_pop_front(t_deque *dq)
{
	if (deque_empty(dq) != 0)
		return (-1);
	dq->front = (dq->front + 1) % dq->max;
	return (dq->data[dq->front]);
}
