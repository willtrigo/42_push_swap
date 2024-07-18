/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/18 19:28:23 by dande-je         ###   ########.fr       */
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
// void	ft_default_operation(t_stacks *stack, t_pivots *pivot);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_set_pivots(stack->a, &pivot);
	if (!ft_is_ready_to_sorted_reverse())
	{
		ft_one_operation_to_finish(stack);
		ft_set_pivots(stack->a, &pivot);
		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		{
			if (pivot.first == pivot.smaller)
				ft_push(PB, ONE_TIME);
			else if (pivot.next == pivot.smaller)
			{
				ft_swap(SA);
				ft_push(PB, ONE_TIME);
			}
			else if (pivot.last == pivot.smaller)
			{
				ft_rotate(RRA, ONE_TIME);
				ft_push(PB, ONE_TIME);
			}
			else if (pivot.first - STACK_NODE == pivot.next)
			{
				ft_swap(SA);
				ft_rotate(RA, TWO_TIMES);
				ft_sort_all();
				return ;
			}
			else if (pivot.last - STACK_NODE == pivot.first)
			{
				// STOP here. ./push_swap 1 4 0 3 2
				if (pivot.next - STACK_NODE == pivot.last)
				{
					ft_swap(SA);
					ft_rotate(RA,ONE_TIME);
				}
				else
				{
					ft_rotate(RRA, ONE_TIME);
					ft_swap(SA);
				}
				ft_set_pivots(stack->a, &pivot);
				while (pivot.first - STACK_NODE == pivot.next)
				{
					if (pivot.first - STACK_NODE == pivot.next)
						ft_swap(SA);
					ft_set_pivots(stack->a, &pivot);
					if (pivot.last - STACK_NODE == pivot.first)
						ft_rotate(RRA, ONE_TIME);
					ft_set_pivots(stack->a, &pivot);
				}
				ft_set_pivots(stack->a, &pivot);
				if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
					ft_sort_all();
				return ;
			}
			else
			{
				while (pivot.next - STACK_NODE == pivot.last)
				{
					ft_swap(SA);
					ft_rotate(RA, ONE_TIME);
					ft_set_pivots(stack->a, &pivot);
				}
				ft_rotate(RA, ONE_TIME);
				ft_set_pivots(stack->a, &pivot);
				if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
					ft_sort_all();
				return ;
			}
			if (stack->info.a_size == SORT_FOUR)
				ft_sort_four(DEFAULT);
			if (stack->info.b_size)
				ft_push(PA, stack->info.b_size);
		}
	}
}

void	ft_one_operation_to_finish(t_stacks *stack)
{
	int	times;

	times = stack->info.a_size - STACK_SIZE_TWO;
	if (ft_is_sorted(stack->a->next->next, DEFAULT, times) && stack->a->nbr - STACK_NODE == stack->a->next->nbr)
		ft_swap(SA);
	else if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size - STACK_NODE))
		ft_rotate(RRA, ONE_TIME);
}
//
// void	ft_default_operation(t_stacks *stack, t_pivots *pivot)
// {
// 	int			count_stack_push;
//
// 	count_stack_push = stack->info.a_size - SORT_FOUR;
// 	while (count_stack_push)
// 	{
// 		if (pivot->first - STACK_NODE == pivot->next && !(pivot->first == pivot->bigger))
// 		{
// 			ft_swap(SA);
// 			ft_set_pivots(stack->a, pivot);
// 			if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
// 				break ;
// 		}
// 		if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) \
// 			&& ((pivot->next == pivot->smaller) && !(pivot->first == pivot->bigger)))
// 		{
// 			ft_swap(SA);
// 			ft_set_pivots(stack->a, pivot);
// 			ft_push(PB, ONE_TIME);
// 			count_stack_push = stack->info.a_size - SORT_FOUR;
// 		}
// 		else if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size) \
// 			&& ((!(pivot->first == pivot->smaller) && !(pivot->first == pivot->bigger))))
// 		{
// 			ft_rotate(RRA, ONE_TIME);
// 			ft_set_pivots(stack->a, pivot);
// 			if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
// 				break ;
// 		}
// 		else if (pivot->first == pivot->smaller || pivot->first == pivot->bigger)
// 		{
// 			ft_push(PB, ONE_TIME);
// 			count_stack_push = stack->info.a_size - SORT_FOUR;
// 		}
// 		if (!stack->info.b_size && ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
// 			count_stack_push = DEFAULT;
// 	}
// }
