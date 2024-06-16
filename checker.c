/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:42:23 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 04:07:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run(t_push_swap *ps)
{
	char	*cmd;
	char	*end;

	if (ps == NULL)
		ps_error();
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		end = ft_strchr(cmd, '\n');
		if (end)
			*end = '\0';
		ps->cmd(ps, cmd);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (ps->b.size == 0 && ps->a.sorted(&ps->a, 0, 1) == ps->a.size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ps_init(&ps);
	ps_parse(&ps, argc - 1, argv + 1);
	run(&ps);
	exit(EXIT_SUCCESS);
}
