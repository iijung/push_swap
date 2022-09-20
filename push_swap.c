/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:48:43 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/20 22:53:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(const char *str, int *rtn)
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

static int	in(t_push_swap *ps, int size, char **arr)
{
	int	i;

	if (ps == 0 || size == 0 || arr == 0)
		return (-1);
	ps->size = size;
	ps->arr = ft_calloc(size, sizeof(int));
	if (ps->arr == 0)
		return (-1);
	if (deque_init(&ps->a, size) < 0 || deque_init(&ps->b, size) < 0)
		return (-1);
	i = -1;
	while (++i < size)
	{
		if (ps_atoi(arr[i], &ps->arr[i]) < 0)
			return (-1);
		if (deque_push_rear(&ps->a, ps->arr[i]) < 0)
			return (-1);
	}
	return (0);
}

static int	run(t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	ft_printf("size: %d\n", deque_count(&ps->a));
	deque_begin(&ps->a);
	deque_begin(&ps->b);
	ft_printf("\nchange\n");
	ps_cmd("sa", ps);
	deque_begin(&ps->a);
	deque_begin(&ps->b);
	ft_printf("\npa\n");
	ps_cmd("pb", ps);
	deque_begin(&ps->a);
	deque_begin(&ps->b);
	ft_printf("\nra\n");
	ps_cmd("ra", ps);
	ps_cmd("ra", ps);
	ps_cmd("ra", ps);
	deque_begin(&ps->a);
	ft_printf("\nrra\n");
	ps_cmd("rra", ps);
	ps_cmd("rra", ps);
	deque_begin(&ps->a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(-1);
	while (1)
	{
		ft_memset(&ps, 0, sizeof(t_push_swap));
		if (in(&ps, argc - 1, argv + 1) < 0 || run(&ps) < 0)
			break ;
		exit(0);
	}
	free(ps.arr);
	free(ps.a.data);
	free(ps.b.data);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
