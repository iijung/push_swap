/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:55 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 06:37:54 by minjungk         ###   ########.fr       */
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
	curr = dq->node[IS_FRONT];
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
	ps_assert(NULL != self, __func__, __FILE__, __LINE__);
	self->rank = rank;
}

static void	ps_set(t_push_swap *ps, char *str)
{
	t_deque_node	*new;
	t_deque_node	*curr;

	new = ft_calloc(1, sizeof(t_deque_node));
	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	ps_assert(NULL != str, __func__, __FILE__, __LINE__);
	ps_assert(NULL != new, __func__, __FILE__, __LINE__);
	errno = 0;
	new->num = ft_atoi(str);
	ps_assert(0 == errno, __func__, __FILE__, __LINE__);
	curr = ps->a.node[IS_FRONT];
	while (curr)
	{
		ps_assert(curr->num != new->num, __func__, __FILE__, __LINE__);
		curr = curr->next;
	}
	ps->a.enque(&ps->a, IS_REAR, new);
	ps_rank(&ps->a, new->num);
}

void	ps_parse(t_push_swap *ps, int size, char **strs)
{
	int		i;
	int		j;
	char	**split;

	ps_assert(NULL != ps && size > 0 && strs, __func__, __FILE__, __LINE__);
	i = -1;
	while (++i < size)
	{
		split = ft_split(strs[i], ' ');
		ps_assert(NULL != split, __func__, __FILE__, __LINE__);
		ps_assert(NULL != split[0], __func__, __FILE__, __LINE__);
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
