/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 06:07:24 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 06:36:37 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

static void	merge(unsigned int *arr, \
	unsigned int p, unsigned int q, unsigned int r)
{
	unsigned int	idx[3];
	unsigned int	*tmp;

	tmp = ft_calloc(r - p + 1, sizeof(unsigned int));
	ps_assert(NULL != tmp, __func__, __FILE__, __LINE__);
	idx[0] = 0;
	idx[1] = p;
	idx[2] = q + 1;
	while (idx[1] <= q && idx[2] <= r)
	{
		if (arr[idx[1]] <= arr[idx[2]])
			tmp[idx[0]++] = arr[idx[1]++];
		if (arr[idx[1]] > arr[idx[2]])
			tmp[idx[0]++] = arr[idx[2]++];
	}
	while (idx[1] <= q)
		tmp[idx[0]++] = arr[idx[1]++];
	while (idx[2] <= r)
		tmp[idx[0]++] = arr[idx[2]++];
	idx[0] = -1;
	while (++idx[0] <= r - p)
		arr[p + idx[0]] = tmp[idx[0]];
	free(tmp);
}

static void	divide(unsigned int *arr, unsigned int left, unsigned int right)
{
	const unsigned int	mid = (left + right) / 2;

	if (left >= right)
		return ;
	divide(arr, left, mid);
	divide(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void	ps_pivot(t_deque *dq, unsigned int size, t_ps_value *val)
{
	unsigned int	*arr;
	t_deque_node	*curr;

	arr = ft_calloc(size, sizeof(unsigned int));
	ps_assert(NULL != dq, __func__, __FILE__, __LINE__);
	ps_assert(NULL != val, __func__, __FILE__, __LINE__);
	ps_assert(NULL != arr, __func__, __FILE__, __LINE__);
	ft_memset(val, 0, sizeof(t_ps_value));
	curr = dq->node[IS_FRONT];
	while (val->size < size && curr)
	{
		arr[val->size++] = curr->rank;
		curr = curr->next;
	}
	divide(arr, 0, size - 1);
	val->min = arr[0];
	val->mid = arr[(size - 1) / 2];
	val->max = arr[size - 1];
	val->pivot1 = arr[size / 3];
	val->pivot2 = arr[size - size / 3];
}

void	ps_restore(t_push_swap *ps, unsigned int ra, unsigned int rb)
{
	ps_assert(NULL != ps, __func__, __FILE__, __LINE__);
	if (ps->a.size <= ra)
		ra = 0;
	if (ps->b.size <= rb)
		rb = 0;
	while (ra && rb)
	{
		ps->cmd(ps, RRR);
		--ra;
		--rb;
	}
	while (ra--)
		ps->cmd(ps, RRA);
	while (rb--)
		ps->cmd(ps, RRB);
}
