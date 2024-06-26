/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2024/06/17 07:09:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libexternal.h"

# define PA		"pa"	// push a
# define PB		"pb"	// push b

# define SS		"ss"	// sa + sb
# define SA		"sa"	// swap a[0] a[1]
# define SB		"sb"	// swap b[0] b[1]

# define RR		"rr"	// ra + rb
# define RA		"ra"	// rotate a (first -> last)
# define RB		"rb"	// rotate b (first -> last)

# define RRR	"rrr"	// rra + rrb
# define RRA	"rra"	// reverse rotate a (last -> first)
# define RRB	"rrb"	// reverse rotate b (last -> first)

enum e_rear
{
	IS_FRONT,
	IS_REAR,
};

enum e_order
{
	DESC,
	ASC,
};

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
	t_deque_node	*(*deque)(struct s_deque *, int);
	void			(*enque)(struct s_deque *, int, t_deque_node *);
	unsigned int	(*sorted)(struct s_deque *, int, int);
	void			(*show)(struct s_deque *);
};

struct s_push_swap
{
	unsigned int	max;
	t_deque			a;
	t_deque			b;
	t_list			*command_list;
	unsigned int	(*cmd)(struct s_push_swap *, char *);
};

void	deque_init(struct s_deque *dq);
void	ps_assert(int is_success, const char *func, const char *file, int line);
void	ps_debug(struct s_push_swap *ps, const char *cmd);
void	ps_init(struct s_push_swap *ps, int size, char **strs);

#endif
