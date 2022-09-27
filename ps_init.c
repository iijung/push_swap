/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:12:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/27 23:10:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(struct s_push_swap *ps, char cmd)
{
	int		tmp;
	t_deque	*from_to[2];

	if (ps == 0)
		return (-1);
	if (cmd == 'a')
	{
		from_to[0] = &ps->b;
		from_to[1] = &ps->a;
	}
	else if (cmd == 'b')
	{
		from_to[0] = &ps->a;
		from_to[1] = &ps->b;
	}
	else
		return (-1);
	if (from_to[0] == 0 || from_to[1] == 0)
		return (-1);
	if (from_to[0]->node[0] == 0)
		return (0);
	if (from_to[0]->deque(from_to[0], 0, &tmp) < 0
		|| from_to[1]->enque(from_to[1], 0, tmp) < 0)
		return (-1);
	return (0);
}

static int	swap(struct s_push_swap *ps, char cmd)
{
	if (ps == 0)
		return (-1);
	if (cmd == 's')
	{
		if (swap(ps, 'a') < 0 || swap(ps, 'b') < 0)
			return (-1);
	}
	else if (cmd == 'a')
	{
		if (ps->a.swap(&ps->a) < 0)
			return (-1);
	}
	else if (cmd == 'b')
	{
		if (ps->b.swap(&ps->b) < 0)
			return (-1);
	}
	return (0);
}

static int	rotate(struct s_push_swap *ps, char cmd, int is_reverse)
{
	int		tmp;

	if (ps == 0)
		return (-1);
	if (cmd == 'r')
	{
		if (rotate(ps, 'a', is_reverse) < 0 || rotate(ps, 'b', is_reverse) < 0)
			return (-1);
	}
	else if (cmd == 'a' && ps->a.node[0])
	{
		if (ps->a.deque(&ps->a, is_reverse, &tmp) < 0
			|| ps->a.enque(&ps->a, !is_reverse, tmp) < 0)
			return (-1);
	}
	else if (cmd == 'b' && ps->b.node[0])
	{
		if (ps->b.deque(&ps->b, is_reverse, &tmp) < 0
			|| ps->b.enque(&ps->b, !is_reverse, tmp) < 0)
			return (-1);
	}
	return (0);
}

static int	command(struct s_push_swap *ps, char *cmd)
{
	if (ps == 0 || cmd == 0)
		return (-1);
	if (!cmd[2] && cmd[0] == 'p' && ft_strchr("ab", cmd[1]))
	{
		if (push(ps, cmd[1]) < 0)
			return (-1);
	}
	else if (!cmd[2] && cmd[0] == 's' && ft_strchr("sab", cmd[1]))
	{
		if (swap(ps, cmd[1]) < 0)
			return (-1);
	}
	else if (!cmd[2] && cmd[0] == 'r' && ft_strchr("rab", cmd[1]))
	{
		if (rotate(ps, cmd[1], 0) < 0)
			return (-1);
	}
	else if (!cmd[3] && !ft_memcmp(cmd, "rr", 2) && ft_strchr("rab", cmd[2]))
	{
		if (rotate(ps, cmd[2], 1) < 0)
			return (-1);
	}
	else
		return (-1);
	if (ps->show)
		ps->show(ps);
	return (0);
}

int	ps_init(struct s_push_swap *ps, void (*show)(struct s_push_swap *))
{
	if (ps == 0)
		return (-1);
	ft_memset(ps, 0, sizeof(t_push_swap));
	if (deque_init(&ps->a) < 0 || deque_init(&ps->b) < 0)
		return (-1);
	ps->show = show;
	ps->command = command;
	return (0);
}
