/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/29 11:34:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, t_pivots *pivot);
static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot);

void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	if (pivot->first > pivot->next && pivot->next < pivot->last)
		ft_swap_possibilities(SA);
	else if (pivot->first > pivot->next && pivot->next > pivot->last)
		ft_rotate_possibilities(RRA, ONE_TIME);
	ft_stack_normalize(STACK_INDEX);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
	{
		ft_push(PB, ONE_TIME);
		if (stack->info.b_size >= STACK_SIZE_TWO)
			ft_best_position_after_push_to_stack_b(stack, pivot);
	}
}

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	int	next_b;
	int	first_b;

	next_b = stack->b->next->nbr;
	first_b = stack->b->nbr;
	if (first_b < pivot->mid)
		ft_rotate_possibilities(RB, ONE_TIME);
	else if (first_b < next_b)
		ft_swap_possibilities(SB);
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
