/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 11:03:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/sort/four/ft_targets_reverse.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_run_sort_four(t_stacks *stack, t_pivots pivot);
static void	ft_run_sort_four_reverse(t_stacks *stack, t_pivots pivot);

void	ft_sort_four(int type)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	if (type == DEFAULT)
	{
		pivot.first = ft_peek(stack->a);
		pivot.bigger = ft_peek_bigger(stack->a);
		pivot.smaller = ft_peek_smaller(stack->a);
		pivot.last = ft_stacklast(stack->a)->nbr;
		pivot.next = stack->a->next->nbr;
	}
	else
	{
		pivot.first = ft_peek(stack->b);
		pivot.bigger = ft_peek_bigger(stack->b);
		pivot.smaller = ft_peek_smaller(stack->b);
		pivot.last = ft_stacklast(stack->b)->nbr;
		pivot.next = stack->b->next->nbr;
	}
	if (type == DEFAULT)
		ft_run_sort_four(stack, pivot);
	else
		ft_run_sort_four_reverse(stack, pivot);
}

static void	ft_run_sort_four(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size))
	{
		ft_rotate(RA, ONE_TIME);
		return ;
	}
	if (ft_is_sorted(stack->a, REVERSE, stack->info.a_size))
	{
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
	else
	{
		if (pivot.first == pivot.bigger)
			ft_target_bigger(pivot);
		else if (pivot.next == pivot.bigger)
			ft_target_next_bigger(pivot);
		else if (pivot.first == (pivot.bigger - STACK_NODE))
			ft_target_penult(pivot);
		else if (pivot.first == (pivot.smaller + STACK_NODE))
			ft_target_next(pivot);
		else
			ft_target_smaller(pivot);
	}
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

static void	ft_run_sort_four_reverse(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a->next, REVERSE, stack->info.b_size))
	{
		ft_rotate(RB, ONE_TIME);
		return ;
	}
	if (ft_is_sorted(stack->b, DEFAULT, stack->info.b_size))
	{
		ft_swap(SB);
		ft_rotate(RB, TWO_TIMES);
	}
	else
	{
		if (pivot.first == pivot.smaller)
			ft_target_smaller_reverse(pivot);
		else if (pivot.next == pivot.smaller)
			ft_target_next_smaller_reverse(pivot);
		else if (pivot.first == (pivot.smaller + STACK_NODE))
			ft_target_penult_reverse(pivot);
		else if (pivot.first == (pivot.bigger - STACK_NODE))
			ft_target_next_reverse(pivot);
		else
			ft_target_bigger_reverse(pivot);
	}
	if (!ft_is_sorted(stack->b, REVERSE, stack->info.b_size))
		ft_swap(SB);
}
