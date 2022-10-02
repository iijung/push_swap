/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:16:23 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 17:52:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_gui(struct s_push_swap *ps)
{
	int				i;
	t_deque_node	*curr_a;
	t_deque_node	*curr_b;

	if (ps == 0)
		return ;
	write(1, "\x1b[2J\x1b[H", 7);
	curr_a = ps->a.node[0];
	curr_b = ps->b.node[0];
	while (curr_a || curr_b)
	{
		i = -1;
		while (++i < 50)
			ft_printf("%c", ' ' + (curr_a && i < curr_a->num) * 3);
		ft_printf(" | ");
		i = -1;
		while (++i < 50)
			ft_printf("%c", ' ' + (curr_b && i < curr_b->num) * 3);
		ft_printf("\n");
		if (curr_a)
			curr_a = curr_a->next;
		if (curr_b)
			curr_b = curr_b->next;
	}
	usleep(10000);
}

void	show_cli(struct s_push_swap *ps)
{
	t_deque_node	*curr;

	if (ps == 0)
		return ;
	curr = ps->a.node[0];
	while (curr)
	{
		ft_printf("%u ", curr->rank);
		curr = curr->next;
	}
	ft_printf(" / ");
	curr = ps->b.node[0];
	while (curr)
	{
		ft_printf("%u ", curr->rank);
		curr = curr->next;
	}
	ft_printf("\n");
}
