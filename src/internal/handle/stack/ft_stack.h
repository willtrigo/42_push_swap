/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/04 05:21:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct s_pivots			t_pivots;
struct s_pivots
{
	int	bigger;
	int	mid;
	int	smaller;
	int	first;
	int	last;
	int	next;
	int	mid_static;
	int	mid_time;
};

typedef struct s_stacks_info	t_stacks_info;
struct s_stacks_info
{
	int	a_size;
	int	b_size;
};

typedef struct s_stack			t_stack;
struct s_stack
{
	int		nbr;
	int		index;
	t_stack	*next;
	t_stack	*prev;
};

typedef struct s_stacks			t_stacks;
struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stacks_info	info;
};

typedef enum e_operations		t_operations;
enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

typedef enum e_stack_targets	t_stack_targets;
enum e_stack_targets
{
	STACK_A,
	STACK_B,
};

enum e_times
{
	ONE_TIME = 1,
	TWO_TIMES,
};

typedef enum e_type				t_type;
enum e_type
{
	STACK_DEFAULT,
	STACK_INDEX,
	STACK_INDEX_REVERSE,
	STACK_NBR,
	STACK_NBR_REVERSE,
};

t_stacks	*ft_stack(void);
void		ft_stacks_destroy(void);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *node_new);
void		ft_stackadd_front(t_stack **stack, t_stack *node_new);
t_stack		*ft_stacknew(int nbr);
void		ft_set_pivots(t_stack *stack, t_pivots *pivot);
void		ft_stack_normalize(t_type type);

#endif
