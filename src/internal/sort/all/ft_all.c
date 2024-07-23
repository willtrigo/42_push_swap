/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/23 05:21:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
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
	if (stack->info.a_size == SORT_THREE)
		ft_sort_three(DEFAULT);
	if (stack->info.b_size)
		ft_push(PA, stack->info.b_size);
}

void	ft_run_sort_all(t_stacks *stack, t_pivots *pivot)
{
	ft_set_pivots(stack->a, pivot);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) && stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (pivot->first - STACK_NODE == pivot->next || pivot->first + STACK_NODE == pivot->next)
			ft_target_is_first_equal_next(stack, pivot);
		else if (pivot->last - STACK_NODE == pivot->first)
			ft_target_is_last_equal_first(stack, pivot);
		else if ((pivot->smaller == pivot->first) \
			|| (pivot->smaller == pivot->next) \
			|| (pivot->smaller == pivot->last))
			ft_target_is_smaller(pivot);
		else
			ft_target_default(stack, pivot);
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
			ft_swap(SA);
		else if (ft_is_sorted(stack->a, DEFAULT, \
			stack->info.a_size - STACK_NODE))
			ft_rotate(RRA, ONE_TIME);
	}
}
