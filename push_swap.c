/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/25 20:45:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run(t_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	ps->show(ps);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(-1);
	while (1)
	{
		if (ps_init(&ps, show_cli) < 0)
			break ;
		if (ps_parse(&ps, argc - 1, argv + 1) < 0)
			break ;
		if (run(&ps) < 0)
			break ;
		exit(0);
	}
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
