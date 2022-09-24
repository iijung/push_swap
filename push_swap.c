/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:48:43 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/25 00:01:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in(t_data *data, int size, char **strs)
{
	if (data == 0 || size == 0 || strs == 0)
		return (-1);
	if (stack_init(&data->a) < 0 || stack_init(&data->b) < 0)
		return (-1);
	if (data_parse(data, size, strs) < 0)
		return (-1);
	return (0);
}

static unsigned int	sort_count(t_stack *st, int asc)
{
	int		cnt;
	t_list	*curr;

	if (st == 0)
		return (-1);
	if (st->cnt < 2)
		return (st->cnt);
	cnt = 1;
	curr = st->front;
	while (curr && curr->next)
	{
		if (*(int *)(curr->content) == *(int *)(curr->next->content))
			return (-1);
		if (asc && *(int *)(curr->content) > *(int *)(curr->next->content))
			break ;
		if (!asc && *(int *)(curr->content) < *(int *)(curr->next->content))
			break ;
		++cnt;
		curr = curr->next;
	}
	return (cnt);
}

static int	run(t_data *data)
{
	int	cnt;
	int	sorted;

	cnt = 1;
	sorted = sort_count(&data->a, 1);
	while (sorted != data->a.cnt)
	{
#if 1
		if (data_command(data, "sa") < 0) return (-1);;
		if (data_command(data, "pb") < 0) return (-1);;
		if (data_command(data, "pb") < 0) return (-1);;
		if (data_command(data, "pb") < 0) return (-1);;
		if (data_command(data, "sa") < 0) return (-1);;
		if (data_command(data, "pa") < 0) return (-1);;
		if (data_command(data, "pa") < 0) return (-1);;
		if (data_command(data, "pa") < 0) return (-1);;
#endif
		sleep(1);
		++cnt;
		sorted = sort_count(&data->a, 1);
	}
	ft_printf("cnt : %d\n", cnt);
	return (0);
}

void	test_leak(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_data	data;

	//atexit(test_leak);
	if (argc < 2)
		exit(-1);
	while (1)
	{
		ft_memset(&data, 0, sizeof(t_data));
		if (in(&data, argc - 1, argv + 1) < 0 || run(&data) < 0)
			break ;
		exit(0);
	}
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
