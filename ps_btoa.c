/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/05 07:07:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	under3(t_push_swap *ps, unsigned int size, t_ps_value *val)
{
	t_deque_node	*node;

	if (ps == 0 || val == 0)
		ps_error();
	if (size == 0)
		return (0);
	if (size == 1)
		return (ps->command(ps, "pa"));
	if (size == 2)
	{
		if (ps->b.node[0]->rank < ps->b.node[1]->rank)
			ps->command(ps, "sb");
		return ((ps->command(ps, "pa") && (ps->command(ps, "pa"))));
	}
	ps_pivot(&ps->b, size, val);
	if (ps->b.node[0]->rank == val->max)
	{
		ps->command(ps, "pa");
		return (under3(ps, size - 1, val));
	}
	node = ps->b.node[0];
	if (node->next->rank > node->next->next->rank)
	{
		if (ps->b.size == 3)
			ps->command(ps, "rb");
		else
			ps->command(ps, "sb");
		return (under3(ps, 3, val));
	}
	if (ps->b.size == 3)
	{
		ps->command(ps, "rrb");
		return (under3(ps, 3, val));
	}
	ps->command(ps, "rb");
	ps->command(ps, "rb");
	ps->command(ps, "pa");
	ps->command(ps, "rrb");
	ps->command(ps, "rrb");
	return (under3(ps, 2, val));
}

static int	check(t_push_swap *ps, unsigned int size, t_ps_value *val)
{
	if (ps == 0 || val == 0)
		ps_error();
	if (size == 0 || ps->b.node[0] == 0)
		return (1);
	if (ps->b.sorted(&ps->b, 0, 0) >= size)
	{
		while (size--)
			ps->command(ps, "pa");
		return (1);
	}
	ps_pivot(&ps->b, size, val);
	if (size < 4)
		return (under3(ps, size, val));
	return (0);
}

void	ps_btoa(t_push_swap *ps, unsigned int size)
{
	t_ps_value		val;

	if (ps == 0)
		ps_error();
	if (check(ps, size, &val))
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
	ps_atob(ps, val.push - val.ra);
	ps_restore(ps, val.ra, val.rb);
	ps_atob(ps, val.ra);
	ps_btoa(ps, val.rb);
}