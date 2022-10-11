/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/12 02:15:38 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	under3(t_push_swap *ps, unsigned int size)
{
	t_deque_node	*node;

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
	unsigned int	sorted;

	if (size < 2 || ps->a.node[0] == 0)
		return (1);
	ps_pivot(&ps->a, size, val);
	sorted = ps->a.sorted(&ps->a, 0, 1);
	if (sorted >= size)
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
	ps_restore(ps, val.ra, val.rb);
	ps_atob(ps, size - val.push);
	ps_btoa(ps, val.rb);
	ps_btoa(ps, val.push - val.rb);
}
