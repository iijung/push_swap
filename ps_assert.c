/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 04:40:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libexternal.h"

#ifndef DEBUG
# define DEBUG 0
#endif

void	ps_assert(int is_success, const char *func, const char *file, int line)
{
	if (is_success)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (DEBUG)
		ft_dprintf(STDERR_FILENO, "\tat %s(%s:%d)\n", func, file, line);
	exit(EXIT_FAILURE);
}
