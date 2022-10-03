/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/04 05:20:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	ps_solve(t_push_swap *ps)
{
	if (ps == 0)
		ps_error();
	ps_atob(ps, ps->max, 0);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(-1);
	ps_init(&ps, show_cli);
	ps_parse(&ps, argc - 1, argv + 1);
	ps_solve(&ps);
	exit(0);
}
