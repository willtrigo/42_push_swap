/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 08:17:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/operation/ft_push.h"

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot);
static void	ft_one_operation_to_finish(t_stack *stack, int info);

void	ft_sort_four(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	pivot.mid = INIT;
	ft_set_pivots(stack->a, &pivot);
	ft_run_sort_four(stack, &pivot);
}

static void	ft_run_sort_four(t_stacks *stack, t_pivots *pivot)
{
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_one_operation_to_finish(stack->a, stack->info.a_size);
		ft_set_pivots(stack->a, pivot);
		if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
		{
			ft_targets(pivot);
			ft_set_pivots(ft_stack()->a, pivot);
			if (ft_stack()->info.a_size <= SORT_THREE)
				ft_sort_three();
			if (ft_stack()->info.b_size && ft_stack()->info.a_size \
				== STACK_SIZE_THREE)
				ft_push(PA, ONE_TIME);
		}
	}
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
		ft_swap_possibilities(SA);
}

static void	ft_one_operation_to_finish(t_stack *stack, int info)
{
	int	times;

	times = info - STACK_NODE;
	if (ft_is_sorted(stack->next, STACK_NBR, times))
		ft_rotate_possibilities(RA, ONE_TIME, false);
	else if (ft_is_sorted(stack->next->next, STACK_NBR, times) \
		&& stack->next->index == DEFAULT)
		ft_swap_possibilities(SA);
	else if (ft_is_sorted(stack, STACK_NBR, times))
		ft_rotate_possibilities(RRA, ONE_TIME, false);
}
