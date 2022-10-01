/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/02 04:10:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_deque_node	t_deque_node;
typedef struct s_deque		t_deque;
typedef struct s_push_swap	t_push_swap;

struct s_deque_node
{
	int				num;
	unsigned int	rank;
	t_deque_node	*prev;
	t_deque_node	*next;
};

struct s_deque
{
	unsigned int	size;
	t_deque_node	*node[2];
	unsigned int	(*sorted)(struct s_deque *, int, int);
	int				(*deque)(struct s_deque *, int, t_deque_node **);
	int				(*enque)(struct s_deque *, int, t_deque_node *);
	int				(*swap)(struct s_deque *dq);
};

struct s_push_swap
{
	unsigned int	max;
	t_deque			a;
	t_deque			b;
	void			(*show)(struct s_push_swap *);
	int				(*command)(struct s_push_swap *, char *);
};

int		deque_init(struct s_deque *dq);
int		ps_init(struct s_push_swap *ps, void (*show)(struct s_push_swap *));
int		ps_parse(struct s_push_swap *ps, int size, char **strs);

void	show_gui(struct s_push_swap *ps);
void	show_cli(struct s_push_swap *ps);
#endif
