/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/28 17:02:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(const char *str, int *rtn)
{
	int	minus;

	minus = 0;
	if (*str == '+' || *str == '-')
		minus = *str++ == '-';
	if (!('0' <= *str && *str <= '9'))
		return (-1);
	*rtn = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (*rtn > 214748364 || (*rtn == 214748364 && (*str > '7' + minus)))
			return (-1);
		*rtn = *rtn * 10 + *str++ - '0';
	}
	if (minus)
		*rtn *= -1;
	return (0);
}

static int	ps_rank(t_deque *dq, int num)
{
	unsigned int	rank;
	t_deque_node	*self;
	t_deque_node	*curr;

	if (dq == 0)
		return (-1);
	rank = 0;
	self = 0;
	curr = dq->node[0];
	while (curr)
	{
		if (curr->num == num)
			self = curr;
		else if (curr->num < num)
			rank += 1;
		else if (curr->num > num)
			curr->rank += 1;
		curr = curr->next;
	}
	if (self == 0)
		return (-1);
	self->rank = rank;
	return (0);
}

static int	ps_set(t_push_swap *ps, char *str)
{
	t_deque_node	*new;
	t_deque_node	*curr;

	if (ps == 0 || str == 0)
		return (-1);
	new = ft_calloc(1, sizeof(t_deque_node));
	if (new == 0)
		return (-1);
	if (ps_atoi(str, &new->num) < 0)
		return (-1);
	curr = ps->a.node[0];
	while (curr)
	{
		if (curr->num == new->num)
			return (-1);
		curr = curr->next;
	}
	if (ps->a.enque(&ps->a, 1, new) < 0)
		return (-1);
	if (ps_rank(&ps->a, new->num) < 0)
		return (-1);
	return (0);
}

int	ps_parse(t_push_swap *ps, int size, char **strs)
{
	int		i;
	int		j;
	char	**split;

	if (ps == 0 || size == 0 || strs == 0)
		return (-1);
	i = -1;
	while (++i < size)
	{
		split = ft_split(strs[i], ' ');
		if (split == 0 || split[0] == 0)
			return (-1);
		j = -1;
		while (split[++j])
		{
			if (ps_set(ps, split[j]) < 0)
				return (-1);
			free(split[j]);
		}
		free(split);
	}
	return (0);
}
