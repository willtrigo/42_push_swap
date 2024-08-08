/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 12:48:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot);

void	ft_sort_three(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	pivot.mid = INIT;
	pivot.mid_static = INIT;
	ft_set_pivots(stack->a, &pivot);
	ft_run_sort_three(stack, pivot);
}

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a, STACK_INDEX_REVERSE, stack->info.a_size))
		ft_rotate_possibilities(RA, ONE_TIME, false);
	else
	{
		if (pivot.first == pivot.bigger)
			ft_rotate_possibilities(RA, ONE_TIME, false);
		else if (pivot.next == pivot.bigger)
		{
			if (pivot.last == pivot.smaller)
				ft_rotate_possibilities(RRA, ONE_TIME, false);
			else
			{
				ft_swap_possibilities(SA);
				ft_rotate_possibilities(RA, ONE_TIME, false);
			}
		}
	}
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
		ft_swap_possibilities(SA);
}
