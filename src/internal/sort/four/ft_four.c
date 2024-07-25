/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 05:20:13 by dande-je         ###   ########.fr       */
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
			ft_targets(pivot);
	}
	ft_stack_normalize(PEEK_INDEX);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap_possibilities(SA);
}

static void	ft_run_sort_four_reverse(t_stacks *stack, t_pivots *pivot)
{
	(void)stack;
	(void)pivot;
}

static void	ft_one_operation_to_finish(t_stack *stack, int info, int type)
{
	int	times;

	times = info - STACK_NODE;
	if (type == DEFAULT)
	{
		if (ft_is_sorted(stack->next, DEFAULT, times))
			ft_rotate_possibilities(RA, ONE_TIME);
		else if (ft_is_sorted(stack->next->next, DEFAULT, times) \
			&& stack->next->index == DEFAULT)
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack, DEFAULT, times))
			ft_rotate_possibilities(RRA, ONE_TIME);
	}
	else
	{
		if (ft_is_sorted(stack->next, REVERSE, times))
			ft_rotate_possibilities(RA, ONE_TIME);
		else if (ft_is_sorted(stack->next->next, REVERSE, times) \
			&& stack->next->index == ft_peek_bigger(ft_stack()->b, PEEK_INDEX))
			ft_swap_possibilities(SA);
		else if (ft_is_sorted(stack, REVERSE, times))
			ft_rotate_possibilities(RRA, ONE_TIME);
	}
}
