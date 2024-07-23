/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/23 05:29:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/sort/all/ft_all.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

void	ft_target_is_smaller(t_pivots *pivot)
{
	if (pivot->first == pivot->smaller)
		ft_push(PB, ONE_TIME);
	else if (pivot->next == pivot->smaller)
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->last == pivot->smaller)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_push(PB, ONE_TIME);
	}
}

void	ft_target_is_first_equal_next(t_stacks *stack, t_pivots *pivot)
{
	(void)pivot;
	(void)stack;
	ft_swap(SA);
	ft_rotate(RA, TWO_TIMES);

	// (void)pivot;
	// (void)stack;
	// if (stack->info.a_size - STACK_SIZE_FOUR < pivot->mid && pivot->first < pivot->mid)
	// {
	// 	if (pivot->first + STACK_NODE == pivot->last)
	// 		ft_swap(SA);
	// 	ft_push(PB, TWO_TIMES);
	// }
	// else
	// {
	// 	// ft_swap(SA);
	// 	ft_rotate(RA, TWO_TIMES);
	// }
}

void	ft_target_is_last_equal_first(t_stacks *stack, t_pivots *pivot)
{
	if (pivot->next - STACK_NODE == pivot->last)
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
	}
	ft_set_pivots(stack->a, pivot);
	while (pivot->first - STACK_NODE == pivot->next)
	{
		if (pivot->first - STACK_NODE == pivot->next)
			ft_swap(SA);
		ft_set_pivots(stack->a, pivot);
		if (pivot->last - STACK_NODE == pivot->first)
			ft_rotate(RRA, ONE_TIME);
	}
}

void	ft_target_default(t_stacks *stack, t_pivots *pivot)
{
	while (pivot->next - STACK_NODE == pivot->last)
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
		ft_set_pivots(stack->a, pivot);
	}
	ft_rotate(RA, ONE_TIME);
}
