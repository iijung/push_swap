/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:24:51 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 07:13:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef DEBUG
# define DEBUG 0
#endif

void	ps_debug(t_push_swap *ps, const char *cmd)
{
	if (DEBUG == 0 || ps == NULL)
		return ;
	ft_printf("%-5s", cmd);
	ps->a.show(&ps->a);
	ft_putstr_fd("/ ", STDOUT_FILENO);
	ps->b.show(&ps->b);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
