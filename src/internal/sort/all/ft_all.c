/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/08 09:50:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/sort/all/ft_cost.h"
#include "internal/sort/all/ft_return_nbrs.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_finder_push_number_to_b(t_stacks *stack, t_pivots *pivot, \
			int smaller_stack_b);
static void	ft_push_number_to_b(t_stacks *stack, t_pivots *pivot);
static void	ft_after_push_numbers_to_stack_b(t_stacks *stack, t_pivots *pivot);
static void	ft_one_operation_to_finish(t_stacks *stack);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	pivot.mid = INIT;
	pivot.mid_time = DEFAULT;
	pivot.mid_static = INIT;
	ft_set_pivots(stack->a, &pivot);
	pivot.mid_static = pivot.mid;
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_finder_push_number_to_b(stack, &pivot, pivot.mid_static);
		ft_after_push_numbers_to_stack_b(stack, &pivot);
		ft_return_sorted_all(stack, &pivot);
	}
}

static void	ft_after_push_numbers_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	while (pivot->bigger + STACK_NODE > STACK_SIZE_FIVE \
		&& stack->info.a_size > STACK_SIZE_FOUR && stack->info.b_size \
		&& !(stack->a->nbr + STACK_SIZE_TWO \
		== stack->a->next->nbr || stack->a->nbr + STACK_NODE \
		== stack->a->next->nbr))
		ft_push(PB, ONE_TIME);
	if (stack->info.a_size <= SORT_FOUR)
		ft_sort_four();
	ft_set_pivots(stack->a, pivot);
	if (pivot->bigger + STACK_NODE > STACK_SIZE_FIVE)
	{
		while (stack->info.a_size > STACK_SIZE_TWO && stack->info.b_size \
			&& !(ft_is_sorted(stack->a, STACK_NBR, stack->info.a_size)))
			ft_push(PB, ONE_TIME);
	}
}

static void	ft_one_operation_to_finish(t_stacks *stack)
{
	int	times;

	times = stack->info.a_size - STACK_SIZE_TWO;
	if (!stack->info.b_size \
		&& !ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
	{
		if (ft_is_sorted(stack->a->next->next, \
			STACK_INDEX, times) && stack->a->nbr - STACK_NODE \
			== stack->a->next->nbr)
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack->a, STACK_INDEX, \
			stack->info.a_size - STACK_NODE))
			ft_rotate_possibilities(RRA, ONE_TIME, false);
	}
}

static void	ft_finder_push_number_to_b(t_stacks *stack, t_pivots *pivot, \
			int smaller_stack_b)
{
	t_cost	direction;

	ft_set_pivots(stack->a, pivot);
	direction = ft_return_best_cost(pivot->mid, STACK_A, false);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size) \
		&& stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (stack->a->nbr < pivot->mid_static + (pivot->mid_static \
			* pivot->mid_time))
			ft_push_number_to_b(stack, pivot);
		else if (direction == TOP)
			ft_rotate_possibilities(RA, ONE_TIME, true);
		else if (direction == BOT)
			ft_rotate_possibilities(RRA, ONE_TIME, true);
		ft_finder_push_number_to_b(stack, pivot, smaller_stack_b);
	}
}

static void	ft_push_number_to_b(t_stacks *stack, t_pivots *pivot)
{
	ft_push(PB, ONE_TIME);
	if (stack->info.b_size > STACK_SIZE_TWO && stack->b->nbr \
		> (pivot->mid_static / STACK_SIZE_TWO) + (pivot->mid_static \
		* pivot->mid_time))
		ft_rotate_possibilities(RB, ONE_TIME, true);
	if (stack->info.b_size == (pivot->mid_static + (pivot->mid_static \
		* pivot->mid_time)))
	{
		pivot->mid = (pivot->mid_static / STACK_SIZE_TWO);
		while (--pivot->mid)
			ft_rotate_possibilities(RRB, ONE_TIME, true);
		pivot->mid_time++;
		pivot->mid = INIT;
	}
}
