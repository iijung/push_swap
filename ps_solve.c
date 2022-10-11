/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 06:07:24 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/11 23:47:01 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_restore(t_push_swap *ps, unsigned int ra, unsigned int rb)
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

void	ps_pivot(t_deque *dq, unsigned int size, t_ps_value *val)
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
	while (val->size < size && curr)
	{
		curr = curr->next;
		if (curr && curr->rank < val->min)
			val->min = curr->rank;
		if (curr && curr->rank > val->max)
			val->max = curr->rank;
		val->size++;
	}
	val->pivot1 = val->min + size / 3;
	val->pivot2 = val->max - size / 3;
}
