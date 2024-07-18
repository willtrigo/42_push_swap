/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/18 08:29:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_four.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

void	ft_one_operation_to_finish(t_stacks *stack);
void	ft_default_operation(t_stacks *stack, t_pivots *pivot);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_ready_to_sorted_reverse())
	{
		// if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) && !stack->info.b_size)
		// 	ft_one_operation_to_finish(stack);
		ft_one_operation_to_finish(stack);
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
			ft_default_operation(stack, &pivot);
		if (stack->info.a_size <= SORT_FOUR)
			ft_sort_four(DEFAULT);
		if (stack->info.b_size)
			ft_push(PA, stack->info.b_size);
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
			ft_rotate(RA, ONE_TIME);
	}
}

void	ft_one_operation_to_finish(t_stacks *stack)
{
	if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size - STACK_NODE))
		ft_rotate(RA, ONE_TIME);
	else if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size - STACK_NODE))
		ft_rotate(RRA, ONE_TIME);
}

void	ft_default_operation(t_stacks *stack, t_pivots *pivot)
{
	int			count_stack_push;

	count_stack_push = stack->info.a_size - SORT_FOUR;
	while (count_stack_push)
	{
		if (pivot->first - STACK_NODE == pivot->next && !(pivot->first == pivot->bigger))
		{
			ft_swap(SA);
			ft_set_pivots(stack->a, pivot);
			if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
				break ;
		}
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) \
			&& ((pivot->next == pivot->smaller) && !(pivot->first == pivot->bigger)))
		{
			ft_swap(SA);
			ft_set_pivots(stack->a, pivot);
			ft_push(PB, ONE_TIME);
			count_stack_push = stack->info.a_size - SORT_FOUR;
		}
		else if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) \
			&& ((!(pivot->first == pivot->smaller) && !(pivot->first == pivot->bigger))))
		{
			ft_rotate(RRA, ONE_TIME);
			ft_set_pivots(stack->a, pivot);
			if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
				break ;
		}
		else if (pivot->first == pivot->smaller || pivot->first == pivot->bigger)
		{
			ft_push(PB, ONE_TIME);
			count_stack_push = stack->info.a_size - SORT_FOUR;
		}
		if (!stack->info.b_size && ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
			count_stack_push = DEFAULT;
	}
}
