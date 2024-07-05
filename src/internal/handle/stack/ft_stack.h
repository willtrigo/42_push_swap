/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 04:41:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

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
	t_stack	*a;
	t_stack	*b;
	size_t	a_len;
	size_t	b_len;
};

t_stacks	*ft_stack(void);
void		ft_print_stack(int target_stack);

#endif
