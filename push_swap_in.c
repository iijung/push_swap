/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:41:25 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/24 21:10:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static int	data_atoi(const char *str, int *rtn)
{
	int				minus;

	minus = 0;
	if (*str == '+' || *str == '-')
		minus = *str++ == '-';
	if (!('0' <= *str && *str <= '9'))
		ft_error();
	*rtn = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (*rtn > 214748364 || (*rtn == 214748364 && (*str > '7' + minus)))
			ft_error();
		*rtn = *rtn * 10 + *str++ - '0';
	}
	if (minus)
		*rtn *= -1;
	return (0);
}

int	data_parse(t_data *data, int size, char **strs)
{
	int		i;
	int		j;
	int		num;
	char	**split;

	if (data == 0 || size == 0 || strs == 0)
		return (-1);
	i = -1;
	while (++i < size)
	{
		split = ft_split(strs[i], ' ');
		if (split == 0 || split[0] == 0)
			return (-1);
		j = -1;
		while (split[++j])
		{
			if (data_atoi(split[j], &num) < 0)
				ft_error();
			if (data->a.push(&data->a, num, 0) < 0)
				ft_error();
			free(split[j]);
		}
		free(split);
	}
	return (0);
}
