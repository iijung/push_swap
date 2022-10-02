/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 20:54:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_atob(t_push_swap *ps)
{
	unsigned int	idx;
	unsigned int	chunk;

	if (ps == 0)
		ps_error();
	idx = 0;
	chunk = 0.000000053 * ps->max * ps->max + 0.03 * ps->max + 14.5;
	while (ps->a.node[0])
	{
		if (ps->a.node[0]->rank > chunk + idx)
			ps->command(ps, "ra");
		else
		{
			ps->command(ps, "pb");
			if (ps->b.node[0]->rank > idx)
				ps->command(ps, "rb");
			++idx;
		}
	}
}

static int	near_front(t_push_swap *ps)
{
	t_deque_node	*front;
	t_deque_node	*rear;

	if (ps == 0)
		ps_error();
	front = ps->b.node[0];
	rear = ps->b.node[1];
	while (front != rear)
	{
		if (front->rank == ps->b.size - 1)
			return (1);
		if (rear->rank == ps->b.size - 1)
			return (0);
		front = front->next;
		rear = rear->prev;
	}
	return (1);
}

void	ps_btoa(t_push_swap *ps)
{
	int				front;

	if (ps == 0)
		ps_error();
	while (ps->b.node[0])
	{
		front = near_front(ps);
		while (ps->b.node[0]->rank != ps->b.size - 1)
		{
			if (front)
				ps->command(ps, "rb");
			else
				ps->command(ps, "rrb");
		}
		ps->command(ps, "pa");
	}
}
