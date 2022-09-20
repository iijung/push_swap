/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:53:22 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/20 19:52:27 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		deque_init(t_deque *dq, int max)
{
	if (dq == 0)
		return (-1);
	dq->max = max + 1;
	dq->data = ft_calloc(max, sizeof(int));
	if (dq->data == 0)
		return (-1);
	return (0);
}

void	deque_begin(t_deque *dq)
{
	int	idx;

	if (deque_empty(dq) != 0)
		return ;
	idx = (dq->front + 1) % dq->max;
	while (idx != dq->rear)
	{
		ft_printf("%d ", dq->data[idx]);
		idx = (idx + 1) % dq->max;
	}
	ft_printf("%d\n", dq->data[idx]);
}

void	deque_end(t_deque *dq)
{
	int	idx;

	if (deque_empty(dq) != 0)
		return ;
	idx = dq->rear;
	while (idx != dq->front + 1)
	{
		ft_printf("%d ", dq->data[idx]);
		idx = (idx - 1 + dq->max) % dq->max;
	}
	ft_printf("%d\n", dq->data[idx]);
}
