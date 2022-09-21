/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:16:54 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/21 11:59:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop(t_stack *st, int *rtn, int is_front)
{
	if (st == 0 || st->arr == 0 || rtn == 0)
		return (0);
	if (st->front == st->rear)
		return (0);
	st->cnt--;
	if (is_front)
	{
		st->front = (st->front + 1) % st->max;
		*rtn = st->arr[st->front];
	}
	else
	{
		*rtn = st->arr[st->rear];
		st->rear = (st->rear - 1 + st->max) % st->max;
	}
	return (st);
}

static t_stack	*push(struct s_stack *st, int n, int is_front)
{
	if (st == 0 || st->arr == 0)
		return (0);
	if (st->front == (st->rear + 1) % st->max)
		return (0);
	st->cnt++;
	if (is_front)
	{
		st->arr[st->front] = n;
		st->front = (st->front - 1 + st->max) % st->max;
	}
	else
	{
		st->rear = (st->rear + 1) % st->max;
		st->arr[st->rear] = n;
	}
	return (st);
}

static t_stack	*swap(struct s_stack *st)
{
	int	cnt;
	int	tmp;

	if (st == 0 || st->arr == 0)
		return (0);
	if (st->front <= st->rear)
		cnt = st->rear - st->front;
	else
		cnt = st->max - st->front + st->rear;
	if (cnt < 2)
		return (st);
	tmp = st->arr[(st->front + 1) % st->max];
	st->arr[(st->front + 1) % st->max] = st->arr[(st->front + 2) % st->max];
	st->arr[(st->front + 2) % st->max] = tmp;
	return (st);
}

static t_stack	*rotate(struct s_stack *st, int to_left)
{
	int	tmp;

	if (st == 0 || st->arr == 0)
		return (0);
	if (to_left)
	{
		if (st->pop(st, &tmp, 1) == 0 || st->push(st, tmp, 0) == 0)
			return (0);
	}
	else
	{
		if (st->pop(st, &tmp, 0) == 0 || st->push(st, tmp, 1) == 0)
			return (0);
	}
	return (st);
}

int	stack_init(t_stack *st, int max)
{
	if (st == 0)
		return (-1);
	st->max = max + 1;
	st->arr = ft_calloc(max + 1, sizeof(int));
	if (st->arr == 0)
		return (-1);
	st->cnt = 0;
	st->front = st->max - 1;
	st->rear = st->max - 1;
	st->pop = pop;
	st->push = push;
	st->swap = swap;
	st->rotate = rotate;
	return (0);
}
