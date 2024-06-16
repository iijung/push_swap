/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 05:39:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

static int	under3(t_push_swap *ps)
{
	t_ps_value	val;

	ps_pivot(&ps->b, 3, &val);
	if (ps->b.node[0]->next->rank == val.max)
		ps->cmd(ps, SB);
	else if (ps->b.node[0]->next->next->rank == val.max && ps->b.size == 3)
		ps->cmd(ps, RRB);
	if (ps->b.node[0]->rank == val.max)
	{
		ps->cmd(ps, PA);
		if (ps->b.node[0]->rank < ps->b.node[0]->next->rank)
			ps->cmd(ps, SB);
		ps->cmd(ps, PA);
		return (ps->cmd(ps, PA));
	}
	ps->cmd(ps, RB) && ps->cmd(ps, SB) && ps->cmd(ps, PA);
	if (ps->b.node[0]->rank < ps->b.node[1]->rank)
		ps->cmd(ps, RRB) && ps->cmd(ps, PA);
	else
		ps->cmd(ps, PA) && ps->cmd(ps, RRB);
	return (ps->cmd(ps, PA));
}

static int	check(t_push_swap *ps, t_ps_value *val, unsigned int size)
{
	if (size < 4)
	{
		if (size == 1)
			return (ps->cmd(ps, PA));
		else if (size == 2)
		{
			if (ps->b.node[0]->rank < ps->b.node[0]->next->rank)
				ps->cmd(ps, SB);
			ps->cmd(ps, PA) && ps->cmd(ps, PA);
		}
		else if (size == 3)
			return (under3(ps));
		return (1);
	}
	if (size <= ps->b.sorted(&ps->b, 0, 0))
	{
		while (size--)
			ps->cmd(ps, PA);
		return (1);
	}
	ps_pivot(&ps->b, size, val);
	return (0);
}

void	ps_btoa(t_push_swap *ps, unsigned int size)
{
	t_ps_value		val;

	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	if (check(ps, &val, size))
		return ;
	while (val.rb + val.push < val.size)
	{
		if (ps->b.node[0]->rank <= val.pivot1)
			val.rb += ps->cmd(ps, RB);
		else
		{
			val.push += ps->cmd(ps, PA);
			if (ps->a.node[0]->rank < val.pivot2)
				val.ra += ps->cmd(ps, RA);
		}
	}
	ps_atob(ps, val.push - val.ra);
	ps_restore(ps, val.ra, val.rb);
	ps_atob(ps, val.ra);
	ps_btoa(ps, val.size - val.push);
}
