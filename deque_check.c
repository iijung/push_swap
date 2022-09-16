/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:48:24 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/16 10:02:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_full(t_deque *dq)
{
	if (dq == 0)
		return (-1);
	return (dq->front == (dq->rear + 1) % dq->max);
}

int	deque_empty(t_deque *dq)
{
	if (dq == 0 || dq->data == 0)
		return (-1);
	return (dq->rear == dq->front);
}

int	deque_front(t_deque *dq)
{
	if (deque_empty(dq) != 0)
		return (-1);
	return (dq->data[(dq->front + 1) % dq->max]);
}

int	deque_rear(t_deque *dq)
{
	if (deque_empty(dq) != 0)
		return (-1);
	return (dq->data[dq->rear]);
}
