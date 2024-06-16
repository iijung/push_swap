/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 06:33:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

static int	under3(t_push_swap *ps, unsigned int size)
{
	t_deque_node *const	node = ps->a.node[IS_FRONT];

	if (ps->a.sorted(&ps->a, IS_FRONT, ASC) >= size)
		return (1);
	if (size == 2)
		return (ps->cmd(ps, SA));
	if (node->rank < node->next->rank)
	{
		if (ps->a.size == 3)
			ps->cmd(ps, RRA);
		else
		{
			ps->cmd(ps, PB);
			under3(ps, 2);
			ps->cmd(ps, PA);
		}
	}
	else if (ps->a.size == 3 && node->rank > node->next->next->rank)
		ps->cmd(ps, RA);
	else if (ps->b.size > 1
		&& ps->b.node[IS_FRONT]->rank < ps->b.node[IS_FRONT]->next->rank)
		ps->cmd(ps, SS);
	else
		ps->cmd(ps, SA);
	return (under3(ps, 3));
}

static int	under4(t_push_swap *ps)
{
	t_ps_value	val;

	ps_pivot(&ps->a, ps->a.size, &val);
	if (ps->a.node[IS_FRONT]->rank == val.max)
		ps->cmd(ps, RA);
	if (ps->a.node[IS_REAR]->prev->rank == val.max)
		ps->cmd(ps, RRA);
	if (ps->a.node[IS_REAR]->rank == val.max)
		return (under3(ps, 3));
	if (ps->a.node[IS_FRONT]->rank == val.min)
		return (ps->cmd(ps, PB) && under3(ps, 3) && ps->cmd(ps, PA));
	if (ps->a.node[IS_REAR]->prev->rank == val.min)
		return (ps->cmd(ps, RRA) && under3(ps, 2) && ps->cmd(ps, RRA));
	return (under3(ps, 3) && ps->cmd(ps, RRA));
}

static int	under5(t_push_swap *ps)
{
	int			swap[2];
	t_ps_value	val;

	ps_pivot(&ps->a, ps->a.size, &val);
	while (val.push < 2)
	{
		if (ps->a.node[IS_FRONT]->rank < val.mid)
			val.push += ps->cmd(ps, PB);
		else if (ps->a.node[IS_FRONT]->next->rank < ps->a.node[IS_REAR]->rank)
			ps->cmd(ps, RA);
		else
			ps->cmd(ps, RRA);
	}
	swap[0] = ps->a.node[IS_FRONT]->rank > ps->a.node[IS_FRONT]->next->rank;
	swap[1] = ps->b.node[IS_FRONT]->rank < ps->b.node[IS_FRONT]->next->rank;
	if (swap[0] && swap[1])
		ps->cmd(ps, SS);
	else if (swap[0])
		ps->cmd(ps, SA);
	else if (swap[1])
		ps->cmd(ps, SB);
	under3(ps, 3);
	ps->cmd(ps, PA) && ps->cmd(ps, PA);
	return (1);
}

static int	check(t_push_swap *ps, t_ps_value *val, unsigned int size)
{
	if (ps->a.sorted(&ps->a, IS_FRONT, ASC) >= size)
		return (1);
	ps_pivot(&ps->a, size, val);
	if (size < 4)
		return (under3(ps, size));
	if (size == 4 && ps->a.size == 4)
		return (under4(ps));
	if (size == 5 && ps->a.size == 5)
		return (under5(ps));
	return (0);
}

void	ps_atob(t_push_swap *ps, unsigned int size)
{
	t_ps_value		val;

	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	if (check(ps, &val, size))
		return ;
	while (val.ra + val.push < val.size)
	{
		if (ps->a.node[IS_FRONT]->rank >= val.pivot2)
			val.ra += ps->cmd(ps, RA);
		else
		{
			val.push += ps->cmd(ps, PB);
			if (ps->b.node[IS_FRONT]->rank > val.pivot1)
				val.rb += ps->cmd(ps, RB);
		}
	}
	ps_restore(ps, val.ra, val.rb);
	ps_atob(ps, size - val.push);
	ps_btoa(ps, val.rb);
	ps_btoa(ps, val.push - val.rb);
}
