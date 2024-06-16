/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:55 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 03:23:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rank(t_deque *dq, int num)
{
	unsigned int	rank;
	t_deque_node	*self;
	t_deque_node	*curr;

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
		ps_error();
	self->rank = rank;
}

static void	ps_set(t_push_swap *ps, char *str)
{
	t_deque_node	*new;
	t_deque_node	*curr;

	new = ft_calloc(1, sizeof(t_deque_node));
	if (ps == 0 || str == 0 || new == 0)
		ps_error();
	errno = 0;
	new->num = ft_atoi(str);
	if (errno)
		ps_error();
	curr = ps->a.node[0];
	while (curr)
	{
		if (curr->num == new->num)
			ps_error();
		curr = curr->next;
	}
	ps->a.enque(&ps->a, 1, new);
	ps_rank(&ps->a, new->num);
}

void	ps_parse(t_push_swap *ps, int size, char **strs)
{
	int		i;
	int		j;
	char	**split;

	if (ps == 0 || size == 0 || strs == 0)
		ps_error();
	i = -1;
	while (++i < size)
	{
		split = ft_split(strs[i], ' ');
		if (split == 0 || split[0] == 0)
			ps_error();
		j = -1;
		while (split[++j])
		{
			ps_set(ps, split[j]);
			free(split[j]);
		}
		free(split);
	}
	ps->max = ps->a.size;
}
