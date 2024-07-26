/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/26 04:34:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, t_pivots *pivot);
static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot);

void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	if (pivot->first - STACK_NODE == pivot->next)
		ft_push(PB, ONE_TIME);
	if (stack->info.b_size >= STACK_SIZE_TWO)
		ft_best_position_after_push_to_stack_b(stack, pivot);
	ft_set_pivots(stack->a, pivot);
	if (stack->info.a_size > STACK_SIZE_FOUR)
		ft_push(PB, ONE_TIME);
	if (stack->info.b_size >= STACK_SIZE_TWO)
		ft_best_position_after_push_to_stack_b(stack, pivot);
}

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	// int	last_b;
	int	next_b;
	int	first_b;

	// last_b = ft_stacklast(stack->b)->nbr;
	next_b = stack->b->next->nbr;
	first_b = stack->b->nbr;
	if (first_b < pivot->mid)
		ft_rotate_possibilities(RB, ONE_TIME);
	else if (first_b + STACK_NODE == next_b)
		ft_swap_possibilities(SB);
	// else if (first_b - STACK_NODE < last_b)
	// 	ft_rotate_possibilities(RB, ONE_TIME);
}

void	ft_stay_in_the_same_stack(t_pivots *pivot)
{
	if (pivot->first + STACK_NODE == pivot->next)
		ft_stay_in_the_same_stack_first_equal_next(pivot);
	else if (pivot->first - STACK_NODE == pivot->next)
	{
		if (pivot->next - STACK_NODE == pivot->last)
		{
			ft_swap_possibilities(SA);
			ft_rotate_possibilities(RA, TWO_TIMES);
		}
		else if (pivot->first + STACK_NODE == pivot->last)
			ft_rotate_possibilities(RRA, ONE_TIME);
		else
			ft_swap_possibilities(SA);
	}
	else if (pivot->first + STACK_NODE == pivot->last)
	{
		ft_rotate_possibilities(RRA, ONE_TIME);
		ft_swap_possibilities(SA);
	}
	else
		ft_rotate_possibilities(RA, ONE_TIME);
}

static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot)
{
	if (pivot->next + STACK_NODE == pivot->last)
	{
		ft_rotate_possibilities(RRA, ONE_TIME);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
	}
	ft_rotate_possibilities(RA, ONE_TIME);
}
