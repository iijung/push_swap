/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:53:22 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/16 10:03:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*deque_init(unsigned int max)
{
	t_deque	*tmp;

	tmp = ft_calloc(1, sizeof(t_deque));
	if (tmp == 0)
		return (0);
	tmp->max = max;
	tmp->data = ft_calloc(max, sizeof(int));
	if (tmp->data)
		return (tmp);
	free(tmp);
	return (0);
}

void	deque_clear(t_deque *dq)
{
	if (dq == 0)
		return ;
	free(dq->data);
	free(dq);
}

void	deque_begin(t_deque *dq)
{
	unsigned int	idx;

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
	unsigned int	idx;

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
