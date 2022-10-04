/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/05 04:59:49 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore(t_push_swap *ps, unsigned int ra, unsigned int rb)
{
	if (ps == 0)
		ps_error();
	while (ra && rb)
	{
		ps->command(ps, "rrr");
		--ra;
		--rb;
	}
	while (ra--)
		ps->command(ps, "rra");
	while (rb--)
		ps->command(ps, "rrb");
}

static void	pivot(t_deque *dq, unsigned int size, t_ps_value *val)
{
	t_deque_node	*curr;

	if (dq == 0 || val == 0)
		ps_error();
	ft_memset(val, 0, sizeof(t_ps_value));
	curr = dq->node[0];
	if (curr == 0)
		return ;
	val->min = curr->rank;
	val->max = curr->rank;
	curr = curr->next;
	while (val->idx++ < size && curr)
	{
		if (curr->rank < val->min)
			val->min = curr->rank;
		if (curr->rank > val->max)
			val->max = curr->rank;
		curr = curr->next;
	}
	val->idx = 0;
	val->size = size;
	val->pivot1 = val->min + size / 3;
	val->pivot2 = val->max - size / 3;
}

static int	under3(t_push_swap *ps, unsigned int size)
{
	t_deque_node	*node;

	if (ps == 0)
		ps_error();
	if (ps->a.sorted(&ps->a, 0, 1) >= size)
		return (1);
	if (size == 2)
		return (ps->command(ps, "sa"));
	node = ps->a.node[0];
	if (node->rank < node->next->rank)
	{
		if (ps->a.size == 3)
			ps->command(ps, "rra");
		else
		{
			ps->command(ps, "pb");
			under3(ps, 2);
			ps->command(ps, "pa");
		}
	}
	else if (ps->a.size == 3 && node->rank > node->next->next->rank)
		ps->command(ps, "ra");
	else
		ps->command(ps, "sa");
	return (under3(ps, 3));
}

static int	check(t_push_swap *ps, unsigned int size, t_ps_value *val)
{
	if (ps == 0)
		ps_error();
	pivot(&ps->a, size, val);
	if (size < 2 || ps->a.node[0] == 0 || ps->a.sorted(&ps->a, 0, 1) >= size)
		return (1);
	if (size < 4)
		return (under3(ps, size));
	return (0);
}

void	ps_atob(t_push_swap *ps, unsigned int size)
{
	t_ps_value		val;

	if (ps == 0)
		ps_error();
	if (check(ps, size, &val))
		return ;
	while (val.ra + val.push < val.size)
	{
		if (ps->a.node[0]->rank >= val.pivot2)
			val.ra += ps->command(ps, "ra");
		else
		{
			val.push += ps->command(ps, "pb");
			if (ps->b.node[0]->rank > val.pivot1)
				val.rb += ps->command(ps, "rb");
		}
	}
	if (ps->a.size == val.ra)
		val.ra = 0;
	restore(ps, val.ra, val.rb);
	ps_atob(ps, val.ra);
	ps_btoa(ps, val.rb);
	ps_btoa(ps, val.push - val.rb);
}
