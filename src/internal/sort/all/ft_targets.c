/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/03 01:33:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_all.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, \
				t_pivots *pivot);
static void	ft_stay_in_the_same_stack_first_equal_next(t_pivots *pivot);

void	ft_run_sort_all(t_stacks *stack, t_pivots *pivot)
{
	return ;
	ft_set_pivots(stack->a, pivot);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size) \
		&& stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (pivot->first < pivot->mid)
			ft_push_to_stack_b(stack, pivot);
		else if (pivot->last < pivot->mid && pivot->last < pivot->next)
			ft_rotate_possibilities(RRA, ONE_TIME);
		else if (pivot->next < pivot->mid)
			ft_swap_possibilities(SA);
		else if (pivot->first >= pivot->mid)
			ft_stay_in_the_same_stack(pivot);
		ft_run_sort_all(stack, pivot);
	}
}

void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	if (pivot->first > pivot->next && pivot->next < pivot->last)
		ft_swap_possibilities(SA);
	else if (pivot->first > pivot->next && pivot->next > pivot->last)
		ft_rotate_possibilities(RRA, ONE_TIME);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
	{
		ft_push(PB, ONE_TIME);
		pivot->mid--;
		if (stack->info.b_size >= STACK_SIZE_THREE)
			ft_best_position_after_push_to_stack_b(stack, pivot);
	}
}

static void	ft_best_position_after_push_to_stack_b(t_stacks *stack, \
				t_pivots *pivot)
{
	if (stack->b->nbr < pivot->mid)
		ft_rotate_possibilities(RB, ONE_TIME);
	if (stack->b->nbr < stack->b->next->nbr)
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
