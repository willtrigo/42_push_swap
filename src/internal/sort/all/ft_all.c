/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 04:25:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

static void	ft_one_operation_to_finish(t_stacks *stack);

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
		ft_swap_possibilities(SA);
}

void	ft_run_sort_all(t_stacks *stack, t_pivots *pivot)
{
	ft_stack_normalize(PEEK_INDEX);
	ft_set_pivots(stack->a, pivot);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) \
		&& stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (pivot->first < pivot->mid)
			ft_push_to_stack_b(stack, pivot);
		else if (pivot->last < pivot->mid)
			ft_rotate(RRA, ONE_TIME);
		else if (pivot->next < pivot->mid)
			ft_swap_possibilities(SA);
		else if (pivot->first >= pivot->mid)
			ft_stay_in_the_same_stack(pivot);
		ft_run_sort_all(stack, pivot);
	}
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
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack->a, DEFAULT, \
			stack->info.a_size - STACK_NODE))
			ft_rotate(RRA, ONE_TIME);
	}
}
