/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 05:41:23 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_sort.h"

static int	dup_check(char *cmd1, char *cmd2)
{
	if (cmd1 == 0 || cmd2 == 0)
		return (0);
	if ((!ft_strncmp(cmd1, SA, 3) && !ft_strncmp(cmd2, SB, 3))
		|| (!ft_strncmp(cmd1, SB, 3) && !ft_strncmp(cmd2, SA, 3)))
		return (1);
	else if ((!ft_strncmp(cmd1, RA, 3) && !ft_strncmp(cmd2, RB, 3))
		|| (!ft_strncmp(cmd1, RB, 3) && !ft_strncmp(cmd2, RA, 3)))
		return (2);
	else if ((!ft_strncmp(cmd1, RRA, 4) && !ft_strncmp(cmd2, RRB, 4))
		|| (!ft_strncmp(cmd1, RRB, 4) && !ft_strncmp(cmd2, RRA, 4)))
		return (3);
	return (0);
}

void	ps_result(t_list *curr)
{
	int	flag;

	while (curr)
	{
		if (curr->next == 0)
			break ;
		flag = dup_check(curr->content, curr->next->content);
		if (flag == 1)
			ft_putendl_fd(SS, STDOUT_FILENO);
		else if (flag == 2)
			ft_putendl_fd(RR, STDOUT_FILENO);
		else if (flag == 3)
			ft_putendl_fd(RRR, STDOUT_FILENO);
		else
			ft_putendl_fd(curr->content, STDOUT_FILENO);
		if (flag)
			curr = curr->next;
		curr = curr->next;
	}
	if (curr)
		ft_putendl_fd(curr->content, STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ps_init(&ps, argc - 1, argv + 1);
	ps_atob(&ps, ps.max);
	ps_result(ps.command_list);
	exit(EXIT_SUCCESS);
}
