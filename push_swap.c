/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:48:43 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/21 12:27:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_show(t_stack *st)
{
	int	idx;

	if (st == 0)
		return ;
	if (st->front == st->rear)
		return ;
	idx = (st->front + 1) % st->max;
	while (idx != st->rear)
	{
		ft_printf("%d ", st->arr[idx]);
		idx = (idx + 1) % st->max;
	}
	ft_printf("%d", st->arr[idx]);
}

static int	data_atoi(const char *str, int *rtn)
{
	int				minus;

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

static int	in(t_data *data, int size, char **strs)
{
	int	i;

	if (data == 0 || size == 0 || strs == 0)
		return (-1);
	data->max = size;
	data->arr = ft_calloc(size, sizeof(int));
	if (data->arr == 0)
		return (-1);
	if (stack_init(&data->a, size) < 0 || stack_init(&data->b, size) < 0)
		return (-1);
	i = -1;
	while (++i < size)
	{
		if (data_atoi(strs[i], &data->arr[i]) < 0)
			return (-1);
		if (data->a.push(&data->a, data->arr[i], 0) < 0)
			return (-1);
	}
	return (0);
}

static unsigned int	sort_count(t_stack *st, int asc)
{
	int	i;
	int	cnt;

	if (st == 0)
		return (-1);
	if (st->cnt < 2)
		return (st->cnt);
	cnt = 1;
	i = (st->front + 1) % st->max;
	while (i != st->rear)
	{
		if (asc && st->arr[i] > st->arr[(i + 1) % st->max])
			break;
		if (!asc && st->arr[i] < st->arr[(i + 1) % st->max])
			break;
		++cnt;
		i = (i + 1) % st->max;
	}
	return (cnt);
}

static int	run(t_data *data)
{
	int	cnt;
	int	sorted;

	if (data == 0)
		return (-1);
	stack_show(&data->a);
	ft_printf("\n");
	cnt = 0;
	sorted = sort_count(&data->a, 1);
	ft_printf("### f[%2d] r[%2d] sorted[%d]: ", data->a.front, data->a.rear, sorted);
	stack_show(&data->a);
	ft_printf(" / ");
	stack_show(&data->b);
	ft_printf("\n");
	while (sorted != data->max)
	{
#if 0
		data_cmd("sa", data);
		data_cmd("pb", data);
		data_cmd("pb", data);
		data_cmd("pb", data);
		data_cmd("sa", data);
		data_cmd("pa", data);
		data_cmd("pa", data);
		data_cmd("pa", data);
#else
	data->a.rotate(&data->a, 0);

	ft_printf("### f[%2d] r[%2d] sorted[%d]: ", data->a.front, data->a.rear, sorted);
	stack_show(&data->a);
	ft_printf(" / ");
	stack_show(&data->b);
	ft_printf("\n");



		sleep(1);
		++cnt;
		sorted = sort_count(&data->a, 1);
#endif
	}
	ft_printf("cnt : %d\n", cnt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit(-1);
	while (1)
	{
		ft_memset(&data, 0, sizeof(t_data));
		if (in(&data, argc - 1, argv + 1) < 0 || run(&data) < 0)
			break ;
		exit(0);
	}
	free(data.arr);
	free(data.a.arr);
	free(data.b.arr);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
