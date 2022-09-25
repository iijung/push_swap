/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:23:54 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/25 20:04:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	idx(struct s_deque *dq, int idx, int *num)
{
	int				i;
	t_deque_node	*curr;

	if (dq == 0 || num == 0 || idx < dq->size)
		return (-1);
	curr = dq->node[0];
	i = 0;
	while (++i < idx)
	{
		if (curr == 0)
			return (-1);
		curr = curr->next;
	}
	*num = curr->num;
	return (0);
}

static int	deque(struct s_deque *dq, int is_rear, int *num)
{
	t_deque_node	*tmp;

	if (!dq || (is_rear != 0 && is_rear != 1) || !num || !dq->node[is_rear])
		return (-1);
	tmp = dq->node[is_rear];
	if (is_rear)
	{
		dq->node[1] = dq->node[1]->prev;
		if (!dq->node[1])
			dq->node[0] = 0;
		else
			dq->node[1]->next = 0;
	}
	else
	{
		dq->node[0] = dq->node[1]->next;
		if (!dq->node[0])
			dq->node[1] = 0;
		else
			dq->node[0]->prev = 0;
	}
	*num = tmp->num;
	free(tmp);
	return (0);
}

static int	enque(struct s_deque *dq, int is_rear, int num)
{
	t_deque_node	*new;

	if (!dq || (is_rear != 0 && is_rear != 1))
		return (-1);
	new = ft_calloc(1, sizeof(t_deque_node));
	if (!new)
		return (-1);
	new->num = num;
	if (!dq->node[is_rear])
	{
		dq->node[0] = new;
		dq->node[1] = new;
	}
	else if (is_rear)
	{
		new->prev = dq->node[1];
		dq->node[1]->next = new;
	}
	else
	{
		new->next = dq->node[0];
		dq->node[0]->prev = new;
	}
	dq->node[is_rear] = new;
	return (0);
}

static int	swap(struct s_deque *dq)
{
	int	tmp;

	if (dq == 0)
		return (-1);
	if (dq->node[0] == 0 || dq->node[0]->next == 0)
		return (0);
	tmp = dq->node[0]->num;
	dq->node[0]->num = dq->node[0]->next->num;
	dq->node[0]->next->num = tmp;
	return (0);
}

int	deque_init(struct s_deque *dq)
{
	if (dq == 0)
		return (-1);
	ft_memset(dq, 0, sizeof(t_deque));
	dq->idx = idx;
	dq->deque = deque;
	dq->enque = enque;
	dq->swap = swap;
	return (0);
}
