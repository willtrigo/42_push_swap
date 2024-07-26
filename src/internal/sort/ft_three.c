/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/26 05:04:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/ft_stack.h"
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
	ft_stack_normalize(STACK_INDEX);
	if (type == DEFAULT)
		ft_set_pivots(stack->a, &pivot);
	else
		ft_set_pivots(stack->b, &pivot);
	if (type == DEFAULT)
		ft_run_sort_three(stack, pivot);
	else
		ft_run_sort_three_reverse(stack, pivot);
}

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a, REVERSE, stack->info.a_size))
		ft_rotate_possibilities(RA, ONE_TIME);
	else
	{
		if (pivot.first == pivot.bigger)
			ft_rotate_possibilities(RA, ONE_TIME);
		else if (pivot.next == pivot.bigger)
		{
			if (pivot.last == pivot.smaller)
				ft_rotate_possibilities(RRA, ONE_TIME);
			else
			{
				ft_swap_possibilities(SA);
				ft_rotate_possibilities(RA, ONE_TIME);
			}
		}
	}
	ft_stack_normalize(STACK_INDEX);
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap_possibilities(SA);
}

static void	ft_run_sort_three_reverse(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->b, DEFAULT, stack->info.b_size))
		ft_rotate_possibilities(RB, ONE_TIME);
	else
	{
		if (pivot.first == pivot.smaller)
			ft_rotate_possibilities(RB, ONE_TIME);
		else if (pivot.next == pivot.smaller)
		{
			if (pivot.last == pivot.bigger)
				ft_rotate_possibilities(RRB, ONE_TIME);
			else
			{
				ft_swap_possibilities(SB);
				ft_rotate_possibilities(RB, ONE_TIME);
			}
		}
	}
	if (!ft_is_sorted(stack->b, REVERSE, stack->info.b_size))
		ft_swap_possibilities(SB);
}
