/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 02:34:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

enum e_moviments
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

typedef struct s_stack	t_stack;
struct s_stack
{
	int		nbr;
	t_stack	*next;
	t_stack	*prev;
};

typedef struct s_stacks	t_stacks;
struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
};

void	ft_print_stack(t_stacks *stack);

#endif
