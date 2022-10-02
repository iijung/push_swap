/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:12:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 17:39:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(struct s_push_swap *ps, char cmd)
{
	t_deque_node	*tmp;
	t_deque			*from_to[2];

	if (ps == 0)
		ps_error();
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
		ps_error();
	if (from_to[0] == 0 || from_to[1] == 0)
		ps_error();
	if (from_to[0]->node[0] == 0)
		return ;
	tmp = from_to[0]->deque(from_to[0], 0);
	from_to[1]->enque(from_to[1], 0, tmp);
}

static void	swap(struct s_push_swap *ps, char cmd)
{
	if (ps == 0)
		ps_error();
	if (cmd == 's' || cmd == 'a')
		ps->a.swap(&ps->a);
	if (cmd == 's' || cmd == 'b')
		ps->b.swap(&ps->b);
}

static void	rotate(struct s_push_swap *ps, char cmd, int is_reverse)
{
	t_deque_node	*tmp;

	if (ps == 0)
		ps_error();
	if (cmd == 'r')
	{
		rotate(ps, 'a', is_reverse);
		rotate(ps, 'b', is_reverse);
	}
	else if (cmd == 'a' && ps->a.node[0])
	{
		tmp = ps->a.deque(&ps->a, is_reverse);
		ps->a.enque(&ps->a, !is_reverse, tmp);
	}
	else if (cmd == 'b' && ps->b.node[0])
	{
		tmp = ps->b.deque(&ps->b, is_reverse);
		ps->b.enque(&ps->b, !is_reverse, tmp);
	}
}

static void	command(struct s_push_swap *ps, char *cmd)
{
	if (ps == 0 || cmd == 0)
		ps_error();
	if (!cmd[2] && cmd[0] == 'p' && ft_strchr("ab", cmd[1]))
		push(ps, cmd[1]);
	else if (!cmd[2] && cmd[0] == 's' && ft_strchr("sab", cmd[1]))
		swap(ps, cmd[1]);
	else if (!cmd[2] && cmd[0] == 'r' && ft_strchr("rab", cmd[1]))
		rotate(ps, cmd[1], 0);
	else if (!cmd[3] && !ft_memcmp(cmd, "rr", 2) && ft_strchr("rab", cmd[2]))
		rotate(ps, cmd[2], 1);
	else
		ps_error();
	ft_printf("%4s\t", cmd);
	ps->show(ps);
	usleep(200000);
}

void	ps_init(struct s_push_swap *ps, void (*show)(struct s_push_swap *))
{
	if (ps == 0)
		ps_error();
	ft_memset(ps, 0, sizeof(t_push_swap));
	deque_init(&ps->a);
	deque_init(&ps->b);
	ps->show = show;
	ps->command = command;
}
