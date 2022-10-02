/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:23:54 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 10:21:08 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	sorted(struct s_deque *dq, int is_rear, int asc)
{
	int				acc;
	unsigned int	cnt;
	t_deque_node	*curr;
	t_deque_node	*next;

	if (dq == 0 || (is_rear != 0 && is_rear != 1))
		return (0);
	cnt = 0;
	acc = 1 + (asc == 0) * -2;
	curr = dq->node[is_rear];
	while (curr)
	{
		++cnt;
		if (is_rear)
			next = curr->prev;
		else
			next = curr->next;
		if (next == 0 || curr->rank + acc != next->rank)
			break ;
		curr = next;
	}
	return (cnt);
}

static t_deque_node	*deque(struct s_deque *dq, int is_rear)
{
	t_deque_node	*node;

	if (!dq || (is_rear != 0 && is_rear != 1))
		ps_error();
	node = dq->node[is_rear];
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
		dq->node[0] = dq->node[0]->next;
		if (!dq->node[0])
			dq->node[1] = 0;
		else
			dq->node[0]->prev = 0;
	}
	dq->size -= 1;
	node->prev = 0;
	node->next = 0;
	return (node);
}

static void	enque(struct s_deque *dq, int is_rear, t_deque_node *node)
{
	if (!dq || (is_rear != 0 && is_rear != 1) || !node)
		ps_error();
	if (!dq->node[is_rear])
	{
		dq->node[0] = node;
		dq->node[1] = node;
	}
	else if (is_rear)
	{
		node->prev = dq->node[1];
		dq->node[1]->next = node;
	}
	else
	{
		node->next = dq->node[0];
		dq->node[0]->prev = node;
	}
	dq->node[is_rear] = node;
	dq->size += 1;
}

static void	swap(struct s_deque *dq)
{
	if (dq == 0)
		ps_error();
	if (dq->node[0] == 0 || dq->node[0]->next == 0)
		return ;
	dq->node[0]->prev = dq->node[0]->next;
	dq->node[0]->next = dq->node[0]->next->next;
	dq->node[0]->prev->next = dq->node[0];
	dq->node[0]->next->prev = dq->node[0];
	dq->node[0] = dq->node[0]->prev;
	dq->node[0]->next = dq->node[0]->prev;
	dq->node[0]->prev = 0;
}

void	deque_init(struct s_deque *dq)
{
	if (dq == 0)
		ps_error();
	ft_memset(dq, 0, sizeof(t_deque));
	dq->sorted = sorted;
	dq->deque = deque;
	dq->enque = enque;
	dq->swap = swap;
}
