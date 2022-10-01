/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 04:37:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(-1);
	ps_init(&ps, show_cli);
	ps_parse(&ps, argc - 1, argv + 1);
	ps.show(&ps);
	exit(0);
}
