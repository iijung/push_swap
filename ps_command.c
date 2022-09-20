/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:31:18 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/20 22:51:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(char cmd, t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	if (cmd == 'a' && deque_swap(&ps->a) == 0)
		return (0);
	if (cmd == 'b' && deque_swap(&ps->b) == 0)
		return (0);
	if (cmd == 's' && deque_swap(&ps->a) ==  0 && deque_swap(&ps->b) == 0)
		return (0);
	return (-1);
}

static int	push(char cmd, t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	if (cmd == 'a' && deque_push(&ps->b, &ps->a) == 0)
		return (0);
	if (cmd == 'b' && deque_push(&ps->a, &ps->b) == 0)
		return (0);
	return (-1);
}

static int	rotate(char cmd, t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	if (cmd == 'a' && deque_rotate(&ps->a) == 0)
		return (0);
	if (cmd == 'b' && deque_rotate(&ps->b) == 0)
		return (0);
	if (cmd == 'r' && deque_rotate(&ps->a) == 0 && deque_rotate(&ps->b) == 0)
		return (0);
	return (-1);
}

static int	rrotate(char cmd, t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	if (cmd == 'a' && deque_rrotate(&ps->a) == 0)
		return (0);
	if (cmd == 'b' && deque_rrotate(&ps->b) == 0)
		return (0);
	if (cmd == 'r' && deque_rrotate(&ps->a) == 0 && deque_rrotate(&ps->b) == 0)
		return (0);
	return (-1);
}

int	ps_cmd(const char *cmd, t_push_swap *ps)
{
	if (cmd == 0 || ps == 0)
		return (-1);
	if (cmd[0] == 's')
		return (swap(cmd[1], ps));
	if (cmd[0] == 'p')
		return (push(cmd[1], ps));
	if (cmd[0] == 'r' && cmd[1] == 'r')
		return (rrotate(cmd[2], ps));
	if (cmd[0] == 'r')
		return (rotate(cmd[1], ps));
	return (-1);
}
