/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 01:53:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

static void	ft_one_operation_to_finish(t_stacks *stack);
void	ft_stay_in_the_same_stack(t_pivots *pivot);
void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot);
void	ft_best_position_after_push_to_stack_b(t_stacks *stack);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_ready_to_sorted_reverse())
		ft_run_sort_all(stack, &pivot);
	if (stack->info.a_size == SORT_FOUR)
		ft_sort_four(DEFAULT);
	if (stack->info.b_size)
		ft_push(PA, stack->info.b_size);
	ft_stack_normalize(PEEK_INDEX);
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

void	ft_run_sort_all(t_stacks *stack, t_pivots *pivot)
{
	ft_stack_normalize(PEEK_INDEX);
	ft_set_pivots(stack->a, pivot);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) && stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (pivot->first < pivot->mid)
			ft_push_to_stack_b(stack, pivot);
		else if (pivot->last < pivot->mid)
			ft_rotate(RRA, ONE_TIME);
		else if (pivot->next < pivot->mid)
			ft_swap(SA);
		else if (pivot->first >= pivot->mid)
			ft_stay_in_the_same_stack(pivot);
		ft_run_sort_all(stack, pivot);
	}
}

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

void	ft_best_position_after_push_to_stack_b(t_stacks *stack)
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

static void	ft_one_operation_to_finish(t_stacks *stack)
{
	int	times;

	times = stack->info.a_size - STACK_SIZE_TWO;
	if (!stack->info.b_size \
		&& !ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
	{
		if (ft_is_sorted(stack->a->next->next, \
			DEFAULT, times) && stack->a->nbr - STACK_NODE \
			== stack->a->next->nbr)
			ft_swap(SA);
		else if (ft_is_sorted(stack->a, DEFAULT, \
			stack->info.a_size - STACK_NODE))
			ft_rotate(RRA, ONE_TIME);
	}
}
