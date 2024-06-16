/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:12:45 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 06:34:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	push(struct s_push_swap *ps, char cmd)
{
	t_deque_node	*tmp;
	t_deque			*from_to[2];

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
	if (from_to[0]->node[0] == 0)
		return (0);
	tmp = from_to[0]->deque(from_to[0], 0);
	from_to[1]->enque(from_to[1], 0, tmp);
	return (1);
}

static unsigned int	swap(struct s_push_swap *ps, char cmd)
{
	t_deque			*dq;
	t_deque_node	*node[2];

	if (cmd == 's')
		return ((swap(ps, 'a') && swap(ps, 'b')) || 1);
	else if (cmd == 'a' && ps->a.size >= 2)
		dq = &ps->a;
	else if (cmd == 'b' && ps->b.size >= 2)
		dq = &ps->b;
	else
		return (0);
	node[0] = dq->deque(dq, IS_FRONT);
	node[1] = dq->deque(dq, IS_FRONT);
	dq->enque(dq, IS_FRONT, node[0]);
	dq->enque(dq, IS_FRONT, node[1]);
	return (1);
}

static unsigned int	rotate(struct s_push_swap *ps, char *cmd)
{
	t_deque_node	*tmp;
	int				is_reverse;

	if (ft_strncmp(cmd, RR, 3) == 0)
		return ((rotate(ps, RA) && rotate(ps, RB)) || 1);
	if (ft_strncmp(cmd, RRR, 4) == 0)
		return ((rotate(ps, RRA) && rotate(ps, RRB)) || 1);
	is_reverse = ft_strncmp(cmd, RR, 2) == 0;
	if (cmd[is_reverse + 1] == 'a' && ps->a.node[0])
	{
		tmp = ps->a.deque(&ps->a, is_reverse);
		ps->a.enque(&ps->a, !is_reverse, tmp);
	}
	else if (cmd[is_reverse + 1] == 'b' && ps->b.node[0])
	{
		tmp = ps->b.deque(&ps->b, is_reverse);
		ps->b.enque(&ps->b, !is_reverse, tmp);
	}
	else
		return (0);
	return (1);
}

static unsigned int	cmd(struct s_push_swap *ps, char *cmd)
{
	t_list			*instruction;
	unsigned int	ret;

	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	ret = 0;
	if (cmd && (!ft_strncmp(cmd, PA, 3) || !ft_strncmp(cmd, PB, 3)))
		ret = push(ps, cmd[1]);
	else if (cmd && (!ft_strncmp(cmd, SS, 3)
			|| (!ft_strncmp(cmd, SA, 3)) || (!ft_strncmp(cmd, SB, 3))))
		ret = swap(ps, cmd[1]);
	else if (cmd && (!ft_strncmp(cmd, RR, 3) || !ft_strncmp(cmd, RRR, 4)
			|| !ft_strncmp(cmd, RA, 3) || !ft_strncmp(cmd, RRA, 4)
			|| !ft_strncmp(cmd, RB, 3) || !ft_strncmp(cmd, RRB, 4)))
		ret = rotate(ps, cmd);
	else
		ps_assert(1, __func__, __FILE__, __LINE__);
	if (ret == 0)
		return (ret);
	instruction = ft_lstnew(NULL);
	ps_assert(NULL != instruction, __func__, __FILE__, __LINE__);
	instruction->content = ft_strdup(cmd);
	ps_assert(NULL != instruction->content, __func__, __FILE__, __LINE__);
	ft_lstadd_back(&ps->command_list, instruction);
	return (ret);
}

extern void	ps_parse(t_push_swap *ps, int size, char **strs);

void	ps_init(struct s_push_swap *ps, int size, char **strs)
{
	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	ft_memset(ps, 0, sizeof(t_push_swap));
	deque_init(&ps->a);
	deque_init(&ps->b);
	ps->cmd = cmd;
	ps_parse(ps, size, strs);
}
