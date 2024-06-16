/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 05:16:46 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_H
# define PS_SORT_H
# include "push_swap.h"

typedef struct s_ps_value	t_ps_value;

struct s_ps_value
{
	unsigned int	min;
	unsigned int	mid;
	unsigned int	max;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	push;
	unsigned int	size;
	unsigned int	pivot1;
	unsigned int	pivot2;
};

void	ps_restore(t_push_swap *ps, unsigned int ra, unsigned int rb);
void	ps_pivot(t_deque *dq, unsigned int size, t_ps_value *val);
void	ps_atob(t_push_swap *ps, unsigned int size);
void	ps_btoa(t_push_swap *ps, unsigned int size);

#endif
