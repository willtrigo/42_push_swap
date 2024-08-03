/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/03 03:38:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/sort/all/ft_cost.h"
#include "internal/sort/all/ft_targets.h"
#include "internal/sort/all/ft_return_nbrs.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

void	ft_push_number_to_b(t_stacks *stack, t_pivots *pivot);
void	ft_after_push_numbers_to_stack_b(t_stacks *stack, t_pivots *pivot);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	pivot.mid = DEFAULT;
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_run_sort_all(stack, &pivot);
		ft_push_number_to_b(stack, &pivot);
		ft_after_push_numbers_to_stack_b(stack, &pivot);
		ft_return_sorted_all(stack, &pivot);
	}
}

void	ft_after_push_numbers_to_stack_b(t_stacks *stack, t_pivots *pivot)
{
	if (stack->info.a_size == SORT_FOUR)
		ft_sort_four();
	ft_set_pivots(stack->a, pivot);
	if (stack->info.b_size)
	{
		while (!(stack->a->nbr + STACK_SIZE_TWO == stack->a->next->nbr \
			|| stack->a->nbr + STACK_NODE == stack->a->next->nbr))
		{
			ft_push(PB, ONE_TIME);
			if (stack->b->nbr < pivot->mid)
				ft_rotate_possibilities(RB, ONE_TIME);
			else if (stack->b->nbr < stack->b->next->nbr)
				ft_swap_possibilities(SB);
		}
	}
}

void	ft_one_operation_to_finish(t_stacks *stack)
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

void	ft_push_number_to_b(t_stacks *stack, t_pivots *pivot)
{
	// return ;
	t_cost	direction;

	ft_set_pivots(stack->a, pivot);
	direction = ft_return_best_cost(pivot->mid, STACK_A, false);
	ft_one_operation_to_finish(stack);
	ft_set_pivots(stack->a, pivot);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size) \
		&& stack->info.a_size > STACK_SIZE_FOUR)
	{
		if (stack->a->index < pivot->mid)
		{
			ft_push(PB, ONE_TIME);
			// if (stack->info.b_size >= STACK_SIZE_TWO && stack->b->nbr > pivot->smaller)
			// 	ft_rotate_possibilities(RB, ONE_TIME);
			// 	ft_swap_possibilities(SB);
			pivot->mid--;
		}
		else if (direction == TOP)
		{
			// if (pivot->first > pivot->next)
			// 	ft_swap_possibilities(SA);
			// ft_set_pivots(stack->a, pivot);
			ft_rotate_possibilities(RA, ONE_TIME);
		}
		else if (direction == BOT)
		{
			// if (pivot->first > pivot->next)
			// 	ft_swap_possibilities(SA);
			ft_rotate_possibilities(RRA, ONE_TIME);
		}
		ft_push_number_to_b(stack, pivot);
	}
}
