/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:10:10 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/18 21:04:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_flow(unsigned long num, char c, int sign)
{
	if (num < LONG_MAX / 10)
		return (0);
	if (num > LONG_MAX / 10 || c > '8')
		return (1);
	if (sign > 0 && c > '7')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	rtn;

	rtn = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (sign > 0 && is_flow(rtn, *str, sign))
			return ((int)LONG_MAX);
		if (sign < 0 && is_flow(rtn, *str, sign))
			return ((int)LONG_MIN);
		rtn = rtn * 10 + *str++ - '0';
	}
	return ((int)(rtn * sign));
}
