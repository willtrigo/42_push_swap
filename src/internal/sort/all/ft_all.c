/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 01:38:39 by dande-je         ###   ########.fr       */
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

static void	ft_return_sorted_all(t_stacks *stack, t_pivots *pivot);
static void	ft_one_operation_to_finish(t_stacks *stack);
static void	ft_return_nbr_between(t_stacks *stack, int value, t_pivots *pivot);
static void	ft_return_nbr(t_stacks *stack, int value, t_pivots *pivot);
static int	ft_get_cost(int value);

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
	ft_stack_normalize(STACK_INDEX);
	ft_set_pivots(stack->a, &pivot);
	if (stack->info.b_size && !(stack->a->nbr + STACK_SIZE_TWO == stack->a->next->nbr || stack->a->nbr + STACK_NODE == stack->a->next->nbr))
	{
		ft_push(PB, ONE_TIME);
		if (stack->b->nbr < pivot.mid)
			ft_rotate_possibilities(RB, ONE_TIME);
		else if (stack->b->nbr < stack->b->next->nbr)
			ft_swap_possibilities(SB);
	}
	ft_return_sorted_all(stack, &pivot);
}

void	ft_run_sort_all(t_stacks *stack, t_pivots *pivot)
{
	ft_stack_normalize(STACK_INDEX);
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
			ft_rotate_possibilities(RRA, ONE_TIME);
	}
}

static void	ft_return_sorted_all(t_stacks *stack, t_pivots *pivot)
{
	// return ;
	// ft_stack_normalize(STACK_INDEX);
	// ft_set_pivots(stack->a, pivot);
	if (stack->info.b_size && stack->a->nbr + STACK_SIZE_TWO == stack->a->next->nbr)
		ft_return_nbr_between(stack, stack->a->nbr + STACK_NODE, pivot);
	// else if (stack->info.b_size && stack->a->nbr + STACK_NODE == stack->a->next->nbr)
	else if (stack->info.b_size)
		ft_return_nbr(stack, stack->a->nbr - STACK_NODE, pivot);
}

static void	ft_return_nbr_between(t_stacks *stack, int value, t_pivots *pivot)
{
	int	cost;
	int	cost_reverse;

	cost = ft_get_cost(value);
	cost_reverse = stack->info.b_size - ft_get_cost(value);
	if (cost > DEFAULT && cost <= cost_reverse)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (cost > cost_reverse)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
	}
	else
	{
		ft_push(PA, ONE_TIME);
		ft_swap_possibilities(SA);
	}
	// ft_stack_normalize(STACK_INDEX);
	// ft_set_pivots(stack->a, pivot);
	ft_return_sorted_all(stack, pivot);
}

static void	ft_return_nbr(t_stacks *stack, int value, t_pivots *pivot)
{
	int	cost;
	int	cost_reverse;

	cost = ft_get_cost(value);
	cost_reverse = stack->info.b_size - ft_get_cost(value);
	if (cost > DEFAULT && cost <= cost_reverse)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
		// while (stack->b->nbr + STACK_NODE != stack->a->nbr)
		// 	ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (cost > cost_reverse)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
	}
	else
		ft_push(PA, ONE_TIME);
	// if (cost <= cost_reverse && cost != DEFAULT)
	// 	ft_rotate_possibilities(RB, ONE_TIME);
	// else if (cost > cost_reverse)
	// 	ft_rotate_possibilities(RRB, ONE_TIME);
	// if (ft_stack()->b->nbr == value)
	// 	ft_push(PA, ONE_TIME);
	// ft_stack_normalize(STACK_INDEX);
	// ft_set_pivots(stack->a, pivot);
	ft_return_sorted_all(stack, pivot);
}

static int	ft_get_cost(int value)
{
	t_stack	*temp_stack;
	int		cost;

	cost = DEFAULT;
	temp_stack = ft_stack()->b;
	while (temp_stack->next)
	{
		if (temp_stack->nbr == value)
			break;
		cost++;
		temp_stack = temp_stack->next;
	}
	return cost;
}
