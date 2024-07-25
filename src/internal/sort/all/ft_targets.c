/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 04:07:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/sort/all/ft_all.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack);
static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot);

void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	if (pivot->first - STACK_NODE == pivot->next)
		ft_push(PB, ONE_TIME);
	if (stack->info.b_size >= STACK_SIZE_TWO)
		ft_best_position_after_push_to_stack_b(stack);
	ft_set_pivots(stack->a, pivot);
	if (stack->info.a_size > STACK_SIZE_FOUR)
		ft_push(PB, ONE_TIME);
	if (stack->info.b_size >= STACK_SIZE_TWO)
		ft_best_position_after_push_to_stack_b(stack);
}

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack)
{
	int	last_b;
	int	next_b;
	int	first_b;

	last_b = ft_stacklast(stack->b)->nbr;
	next_b = stack->b->next->nbr;
	first_b = stack->b->nbr;
	if (first_b + STACK_NODE == next_b)
		ft_swap(SB);
	else if (first_b - STACK_NODE < last_b)
		ft_rotate(RB, ONE_TIME);
}

void	ft_stay_in_the_same_stack(t_pivots *pivot)
{
	if (pivot->first + STACK_NODE == pivot->next)
		ft_stay_in_the_same_stack_first_equal_next(pivot);
	else if (pivot->first - STACK_NODE == pivot->next)
	{
		if (pivot->next - STACK_NODE == pivot->last)
		{
			ft_swap(SA);
			ft_rotate(RA, TWO_TIMES);
		}
		else if (pivot->first + STACK_NODE == pivot->last)
			ft_rotate(RRA, ONE_TIME);
	}
	else if (pivot->first + STACK_NODE == pivot->last)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
	}
	else
		ft_rotate(RA, ONE_TIME);
}

static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot)
{
	if (pivot->next + STACK_NODE == pivot->last)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	ft_rotate(RA, ONE_TIME);
}
