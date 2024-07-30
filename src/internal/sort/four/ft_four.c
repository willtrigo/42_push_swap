/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 02:44:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot);
static void	ft_one_operation_to_finish(t_stack *stack, int info, int type);

void	ft_sort_four(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_stack_normalize(STACK_INDEX);
	ft_set_pivots(stack->a, &pivot);
	ft_run_sort_four(stack, &pivot);
}

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot)
{
	ft_stack_normalize(STACK_INDEX);
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_one_operation_to_finish(stack->a, stack->info.a_size, DEFAULT);
		ft_set_pivots(stack->a, pivot);
		if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
			ft_targets(pivot);
	}
	ft_stack_normalize(STACK_INDEX);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
		ft_swap_possibilities(SA);
}

static void	ft_one_operation_to_finish(t_stack *stack, int info, int type)
{
	int	times;

	times = info - STACK_NODE;
	if (type == DEFAULT)
	{
		if (ft_is_sorted(stack->next, STACK_INDEX, times))
			ft_rotate_possibilities(RA, ONE_TIME);
		else if (ft_is_sorted(stack->next->next, STACK_INDEX, times) \
			&& stack->next->index == DEFAULT)
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack, STACK_INDEX, times))
			ft_rotate_possibilities(RRA, ONE_TIME);
	}
	else
	{
		if (ft_is_sorted(stack->next, STACK_INDEX_REVERSE, times))
			ft_rotate_possibilities(RA, ONE_TIME);
		else if (ft_is_sorted(stack->next->next, STACK_INDEX_REVERSE, times) \
			&& stack->next->index == ft_peek_bigger(ft_stack()->b, STACK_INDEX))
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack, STACK_INDEX_REVERSE, times))
			ft_rotate_possibilities(RRA, ONE_TIME);
	}
}
