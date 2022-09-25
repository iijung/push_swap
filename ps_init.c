/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:12:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/25 19:36:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show(struct s_push_swap *ps)
{
	t_deque_node	*curr;

	if (ps == 0)
		return ;
	curr = ps->a.node[0];
	while (curr)
	{
		ft_printf("%d ", curr->num);
		curr = curr->next;
	}
	ft_printf(" / ");
	curr = ps->b.node[0];
	while (curr)
	{
		ft_printf("%d ", curr->num);
		curr = curr->next;
	}
	ft_printf("\n");
}

static int	control(struct s_push_swap *ps, char *cmd)
{
	if (ps == 0 || cmd == 0)
		return (-1);
	return (0);
}

int	ps_init(struct s_push_swap *ps)
{
	if (ps == 0)
		return (-1);
	if (deque_init(&ps->a) < 0 || deque_init(&ps->b) < 0)
		return (-1);
	ps->show = show;
	ps->control = control;
	return (0);
}
