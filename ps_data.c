/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:27:04 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/21 22:02:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_strchr("rab", cmd1) == 0)
			return (-1);
		if (ft_strchr("ra", cmd1) && data->a.rotate(&data->a, 1) < 0)
			return (-1);
		if (ft_strchr("rb", cmd1) && data->b.rotate(&data->b, 1) < 0)
			return (-1);
	}
	else if (cmd1 == 'r')
	{
		if (ft_strchr("rab", cmd2) == 0)
			return (-1);
		if (ft_strchr("ra", cmd2) && data->a.rotate(&data->a, 0) < 0)
			return (-1);
		if (ft_strchr("rb", cmd2) && data->b.rotate(&data->b, 0) < 0)
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
	if (cmd[0] == 'p')
	{
		if (ft_strchr("ab", cmd[1]) == 0 || push(data, cmd[1]) < 0)
			return (-1);
	}
	else if (cmd[0] == 's')
	{
		if (ft_strchr("sab", cmd[1]) == 0 || swap(data, cmd[1]) < 0)
			return (-1);
	}
	else if (cmd[0] == 'r')
	{
		if (rotate(data, cmd[1], cmd[2]) < 0)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
