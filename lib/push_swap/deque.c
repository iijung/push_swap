/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:23:54 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 06:05:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	sorted(struct s_deque *dq, int is_rear, int asc)
{
	int				acc;
	unsigned int	cnt;
	t_deque_node	*curr;
	t_deque_node	*next;

	if (dq == NULL || (is_rear != 0 && is_rear != 1))
		return (0);
	cnt = 0;
	acc = 1 + (asc == DESC) * -2;
	curr = dq->node[is_rear];
	while (curr)
	{
		++cnt;
		if (is_rear)
			next = curr->prev;
		else
			next = curr->next;
		if (next == NULL || curr->rank + acc != next->rank)
			break ;
		curr = next;
	}
	return (cnt);
}

static t_deque_node	*deque(struct s_deque *dq, int is_rear)
{
	t_deque_node	*node;

	ps_assert(NULL != dq, __func__, __FILE__, __LINE__);
	ps_assert(0 == is_rear || 1 == is_rear, __func__, __FILE__, __LINE__);
	node = dq->node[is_rear];
	if (is_rear)
	{
		dq->node[1] = dq->node[1]->prev;
		if (dq->node[1] == NULL)
			dq->node[0] = NULL;
		else
			dq->node[1]->next = NULL;
	}
	else
	{
		dq->node[0] = dq->node[0]->next;
		if (dq->node[0] == NULL)
			dq->node[1] = NULL;
		else
			dq->node[0]->prev = NULL;
	}
	dq->size -= 1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	enque(struct s_deque *dq, int is_rear, t_deque_node *node)
{
	ps_assert(NULL != dq, __func__, __FILE__, __LINE__);
	ps_assert(0 == is_rear || 1 == is_rear, __func__, __FILE__, __LINE__);
	ps_assert(NULL != node, __func__, __FILE__, __LINE__);
	if (dq->node[is_rear] == NULL)
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

void	deque_init(struct s_deque *dq)
{
	ps_assert(NULL != dq, __func__, __FILE__, __LINE__);
	ft_bzero(dq, sizeof(t_deque));
	dq->sorted = sorted;
	dq->deque = deque;
	dq->enque = enque;
}
