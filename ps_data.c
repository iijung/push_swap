/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:27:04 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/24 23:42:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aashow(void *num)
{
	int	*n;

	n = num;
	if (*n)
		ft_printf("%d ", *n);
}

static int	push(struct s_data *data, char cmd)
{
	int	tmp;

	if (data == 0)
		return (-1);
	if (cmd == 'a')
	{
		if (data->b.pop(&data->b, &tmp, 1) < 0)
			return (-1);
		if (data->a.push(&data->a, tmp, 1) < 0)
			return (-1);
	}
	else if (cmd == 'b')
	{
		if (data->a.pop(&data->a, &tmp, 1) < 0)
			return (-1);
		if (data->b.push(&data->b, tmp, 1) < 0)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

static int	swap(struct s_data *data, char cmd)
{
	if (data == 0)
		return (-1);
	if (cmd == 's' || cmd == 'a')
	{
		if (data->a.swap(&data->a) < 0)
			return (-1);
	}
	if (cmd == 's' || cmd == 'b')
	{
		if (data->b.swap(&data->b) < 0)
			return (-1);
	}
	return (0);
}

static int	rotate(struct s_data *data, char cmd1, char cmd2)
{
	if (data == 0)
		return (-1);
	if (cmd2 == 0)
	{
		if ((cmd1 == 'r' || cmd1 == 'a') && data->a.rotate(&data->a, 1) < 0)
			return (-1);
		if ((cmd1 == 'r' || cmd1 == 'b') && data->b.rotate(&data->b, 1) < 0)
			return (-1);
	}
	else if (cmd1 == 'r' && ft_strchr("rab", cmd2))
	{
		if ((cmd2 == 'r' || cmd2 == 'a') && data->a.rotate(&data->a, 0) < 0)
			return (-1);
		if ((cmd2 == 'r' || cmd2 == 'b') && data->b.rotate(&data->b, 0) < 0)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	data_command(struct s_data *data, char *cmd)
{
	if (data == 0 || cmd == 0)
		return (-1);
	if (cmd[0] == 'p' && ft_strlen(cmd) == 2)
	{
		if (ft_strchr("ab", cmd[1]) == 0 || push(data, cmd[1]) < 0)
			return (-1);
	}
	else if (cmd[0] == 's' && ft_strlen(cmd) == 2)
	{
		if (ft_strchr("sab", cmd[1]) == 0 || swap(data, cmd[1]) < 0)
			return (-1);
	}
	else if (cmd[0] == 'r' && ft_strlen(cmd) <= 3)
	{
		if (ft_strchr("rab", cmd[1]) == 0 || rotate(data, cmd[1], cmd[2]) < 0)
			return (-1);
	}
	else
		return (-1);
	ft_lstiter(data->a.front, aashow);
	ft_printf(" / ");
	ft_lstiter(data->b.front, aashow);
	ft_printf("\n");
	return (0);
}
