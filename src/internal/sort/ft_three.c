/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 07:52:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot);
static void	ft_run_sort_three_reverse(t_stacks *stack, t_pivots pivot);

void	ft_sort_three(int type)
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
		ft_run_sort_three(stack, pivot);
	else
		ft_run_sort_three_reverse(stack, pivot);
}

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a, REVERSE, stack->info.a_size))
		ft_rotate(RA, ONE_TIME);
	else
	{
		if (pivot.first == pivot.bigger)
			ft_rotate(RA, ONE_TIME);
		else if (pivot.next == pivot.bigger)
		{
			if (pivot.last == pivot.smaller)
				ft_rotate(RRA, ONE_TIME);
			else
			{
				ft_swap(SA);
				ft_rotate(RA, ONE_TIME);
			}
		}
	}
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

static void	ft_run_sort_three_reverse(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->b, DEFAULT, stack->info.b_size))
		ft_rotate(RB, ONE_TIME);
	else
	{
		if (pivot.first == pivot.smaller)
			ft_rotate(RB, ONE_TIME);
		else if (pivot.next == pivot.smaller)
		{
			if (pivot.last == pivot.bigger)
				ft_rotate(RRB, ONE_TIME);
			else
			{
				ft_swap(SB);
				ft_rotate(RB, ONE_TIME);
			}
		}
	}
	if (!ft_is_sorted(stack->b, REVERSE, stack->info.b_size))
		ft_swap(SB);
}
