/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/05 14:55:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	under3(t_push_swap *ps, unsigned int size)
{
	t_ps_value		val;
	t_deque_node	*node;

	if (ps == 0)
		ps_error();
	if (size == 1)
		return (ps->command(ps, "pa"));
	ps_pivot(&ps->b, size, &val);
	if (ps->b.node[0]->rank == val.max)
	{
		ps->command(ps, "pa");
		return (under3(ps, size - 1));
	}
	if (size == 2)
		return (ps->command(ps, "sb") && under3(ps, 2));
	node = ps->b.node[0];
	if (node->next->rank > node->next->next->rank)
	{
		if (ps->b.size == 3)
			ps->command(ps, "rb");
		else
			ps->command(ps, "sb");
		return (under3(ps, 3));
	}
	if (ps->b.size == 3)
	{
		ps->command(ps, "rrb");
		return (under3(ps, 3));
	}
	ps->command(ps, "rb");
	ps->command(ps, "rb");
	ps->command(ps, "pa");
	ps->command(ps, "rrb");
	ps->command(ps, "rrb");
	return (under3(ps, 2));
}

static int	check(t_push_swap *ps, unsigned int size)
{
	unsigned int	sorted;

	if (ps == 0)
		ps_error();
	if (size == 0 || ps->b.node[0] == 0)
		return (1);
	if (size < 4)
		return (under3(ps, size));
	sorted = ps->b.sorted(&ps->b, 0, 0);
	if (sorted >= size)
	{
		while (size--)
			ps->command(ps, "pa");
		return (1);
	}
	return (0);
}

void	ps_btoa(t_push_swap *ps, unsigned int size, unsigned int reverse)
{
	t_ps_value		val;

	if (ps == 0)
		ps_error();
	ps_pivot(&ps->b, size, &val);
	while (val.idx++ < reverse)
		ps->command(ps, "rrb");
	if (check(ps, size))
		return ;
	while (val.rb + val.push < size)
	{
		if (ps->b.node[0]->rank <= val.pivot1)
			val.rb += ps->command(ps, "rb");
		else
		{
			val.push += ps->command(ps, "pa");
			if (ps->a.node[0]->rank < val.pivot2)
				val.ra += ps->command(ps, "ra");
		}
	}
	if (ps->b.size == val.rb)
		val.rb = 0;
	ps_atob(ps, val.push - val.ra, 0);
	ps_atob(ps, val.ra, val.ra);
	ps_btoa(ps, size - val.push, val.rb);
}
