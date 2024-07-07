/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 13:28:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct s_pivots			t_pivots;
struct s_pivots
{
	int	bigger;
	int	smaller;
};

typedef struct s_stacks_info	t_stacks_info;
struct s_stacks_info
{
	int	a_len;
	int	b_len;
	int	max_nbr;
	int	min_nbr;
};

typedef struct s_stack			t_stack;
struct s_stack
{
	int		nbr;
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

t_stacks	*ft_stack(void);
void		ft_print_stack(int target_stack);

#endif