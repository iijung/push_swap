/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 05:05:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_atob(t_push_swap *ps, unsigned int size);

static int	dup_check(char *cmd1, char *cmd2)
{
	if (cmd1 == 0 || cmd2 == 0)
		return (0);
	if ((!ft_strncmp(cmd1, "sa", 3) && !ft_strncmp(cmd2, "sb", 3))
		|| (!ft_strncmp(cmd1, "sb", 3) && !ft_strncmp(cmd2, "sa", 3)))
		return (1);
	else if ((!ft_strncmp(cmd1, "ra", 3) && !ft_strncmp(cmd2, "rb", 3))
		|| (!ft_strncmp(cmd1, "rb", 3) && !ft_strncmp(cmd2, "ra", 3)))
		return (2);
	else if ((!ft_strncmp(cmd1, "rra", 4) && !ft_strncmp(cmd2, "rrb", 4))
		|| (!ft_strncmp(cmd1, "rrb", 4) && !ft_strncmp(cmd2, "rra", 4)))
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
			ft_printf("ss\n");
		else if (flag == 2)
			ft_printf("rr\n");
		else if (flag == 3)
			ft_printf("rrr\n");
		else
			ft_printf("%s\n", curr->content);
		if (flag)
			curr = curr->next;
		curr = curr->next;
	}
	if (curr)
		ft_printf("%s\n", curr->content);
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
