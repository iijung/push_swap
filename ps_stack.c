/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:16:54 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/24 23:48:31 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop(t_stack *st, int *rtn, int is_front)
{
	t_list	*prev;
	t_list	*curr;

	if (st == 0 || rtn == 0 || st->front == 0)
		return (-1);
	prev = 0;
	curr = st->front;
	if (is_front)
		st->front = st->front->next;
	else
	{
		while (curr && curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = 0;
	}
	if (curr == 0)
		return (-1);
	st->cnt--;
	*rtn = *(int *)curr->content;
	free(curr->content);
	free(curr);
	return (0);
}

static int	push(struct s_stack *st, int n, int is_front)
{
	int		*num;
	t_list	*curr;

	if (st == 0)
		return (-1);
	num = ft_calloc(1, sizeof(int));
	if (num == 0)
		return (-1);
	*num = n;
	curr = ft_lstnew(num);
	if (curr == 0)
	{
		free(num);
		return (-1);
	}
	if (is_front)
		ft_lstadd_front(&st->front, curr);
	else
		ft_lstadd_back(&st->front, curr);
	st->cnt++;
	return (0);
}

static int	swap(struct s_stack *st)
{
	int	tmp;

	if (st == 0)
		return (-1);
	if (st->front == 0 || st->front->next == 0)
		return (0);
	tmp = *(int *)(st->front->content);
	*(int *)(st->front->content) = *(int *)(st->front->next->content);
	*(int *)(st->front->next->content) = tmp;
	return (0);
}

static int	rotate(struct s_stack *st, int to_left)
{
	int	tmp;

	if (st == 0)
		return (-1);
	if (to_left)
	{
		if (st->pop(st, &tmp, 1) < 0 || st->push(st, tmp, 0) < 0)
			return (-1);
	}
	else
	{
		if (st->pop(st, &tmp, 0) < 0 || st->push(st, tmp, 1) < 0)
			return (-1);
	}
	return (0);
}

int	stack_init(t_stack *st)
{
	if (st == 0)
		return (-1);
	st->cnt = 0;
	st->front = 0;
	st->rear = 0;
	st->pop = pop;
	st->push = push;
	st->swap = swap;
	st->rotate = rotate;
	return (0);
}
