/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 02:27:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/sort/four/ft_targets_reverse.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/operation/ft_push.h"

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot);
static void	ft_run_sort_four_reverse(t_stacks *stack, t_pivots *pivot);
static void	ft_one_operation_to_finish(t_stack *stack, int info, int type);

void	ft_sort_four(int type)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_stack_normalize(PEEK_INDEX);
	if (type == DEFAULT)
		ft_set_pivots(stack->a, &pivot);
	else
		ft_set_pivots(stack->b, &pivot);
	if (type == DEFAULT)
		ft_run_sort_four(stack, &pivot);
	else
		ft_run_sort_four_reverse(stack, &pivot);
}

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot)
{
	ft_stack_normalize(PEEK_INDEX);
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_one_operation_to_finish(stack->a, stack->info.a_size, DEFAULT);
		ft_set_pivots(stack->a, pivot);
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		{
			if (pivot->first == pivot->smaller)
				ft_push(PB, ONE_TIME);
			else if (pivot->first == pivot->smaller + STACK_NODE)
				ft_target_small_mid(pivot);
			else if (pivot->first == pivot->bigger - STACK_NODE)
				ft_target_penult(pivot);
			else if (pivot->first == pivot->bigger)
				ft_target_bigger(pivot);
			ft_set_pivots(stack->a, pivot);
			ft_stack_normalize(PEEK_INDEX);
			if (stack->info.a_size <= SORT_THREE)
				ft_sort_three(DEFAULT);
			if (stack->info.b_size && stack->info.a_size == STACK_SIZE_THREE)
				ft_push(PA, ONE_TIME);
		}
	}
	ft_stack_normalize(PEEK_INDEX);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

static void	ft_run_sort_four_reverse(t_stacks *stack, t_pivots *pivot)
{
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_one_operation_to_finish(stack->a, stack->info.a_size, DEFAULT);
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		{
			if (pivot->first == pivot->smaller)
				ft_push(PB, ONE_TIME);
			else if (pivot->first == pivot->smaller + STACK_NODE)
				ft_target_small_mid(pivot);
			else if (pivot->first == pivot->bigger - STACK_NODE)
				ft_target_penult(pivot);
			else if (pivot->first == pivot->bigger)
				ft_target_bigger(pivot);
			if (stack->info.a_size <= SORT_THREE)
				ft_sort_three(DEFAULT);
			if (stack->info.b_size)
				ft_push(PA, stack->info.b_size);
		}
	}
}

static void	ft_one_operation_to_finish(t_stack *stack, int info, int type)
{
	int	times;

	times = info - STACK_NODE;
	if (type == DEFAULT)
	{
		if (ft_is_sorted(stack->next, DEFAULT, times))
			ft_rotate(RA, ONE_TIME);
		else if (ft_is_sorted(stack->next->next, DEFAULT, times) \
			&& stack->next->index == DEFAULT)
			ft_swap(SA);
		else if (ft_is_sorted(stack, DEFAULT, times))
			ft_rotate(RRA, ONE_TIME);
	}
	else
	{
		if (ft_is_sorted(stack->next, REVERSE, times))
			ft_rotate(RA, ONE_TIME);
		else if (ft_is_sorted(stack, REVERSE, times))
			ft_rotate(RRA, ONE_TIME);
	}
}
