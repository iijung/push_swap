/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:05:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/13 03:48:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	ps_result(t_list *curr)
{
	char	*cmd1;
	char	*cmd2;

	while (curr)
	{
		if (curr->next == 0)
		{
			ft_printf("%s\n", curr->content);
			break ;
		}
		cmd1 = curr->content;
		cmd2 = curr->next->content;
		curr = curr->next;
		if ((!ft_strncmp(cmd1, "sa", 3) && !ft_strncmp(cmd2, "sb", 3))
			|| (!ft_strncmp(cmd1, "sb", 3) && !ft_strncmp(cmd2, "sa", 3)))
			ft_printf("ss\n");
		else if ((!ft_strncmp(cmd1, "ra", 3) && !ft_strncmp(cmd2, "rb", 3))
			|| (!ft_strncmp(cmd1, "rb", 3) && !ft_strncmp(cmd2, "ra", 3)))
			ft_printf("rr\n");
		else if ((!ft_strncmp(cmd1, "rra", 4) && !ft_strncmp(cmd2, "rrb", 4))
			|| (!ft_strncmp(cmd1, "rrb", 4) && !ft_strncmp(cmd2, "rra", 4)))
			ft_printf("rrr\n");
		else
		{
			ft_printf("%s\n", cmd1);
			continue ;
		}
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		exit(-1);
	ps_init(&ps, show_cli);
	ps_parse(&ps, argc - 1, argv + 1);
	ps_atob(&ps, ps.max);
//	ps_result(ps.command_list);
	exit(0);
}
