/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/25 19:43:37 by minjungk         ###   ########.fr       */
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

int	ps_parse(t_push_swap *ps, int size, char **strs)
{
	int		i;
	int		j;
	int		num;
	char	**split;

	if (ps == 0 || size == 0 || strs == 0)
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
			if (ps_atoi(split[j], &num) < 0)
				return (-1);
			if (ps->a.enque(&ps->a, 1, num) < 0)
				return (-1);
			free(split[j]);
		}
		free(split);
	}
	return (0);
}
