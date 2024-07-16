/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 11:26:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"

// static bool	ft_sort_target_max_nbr(t_stacks *stack);
// static void	ft_push_nbr_back(t_stacks *stack);

void	ft_sort_all(void)
{
	t_stacks	*stack;
	t_pivots	pivot;
	int			count_stack_push;

	stack = ft_stack();
	pivot.first = ft_peek(stack->a);
	pivot.bigger = ft_peek_bigger(stack->a);
	pivot.smaller = ft_peek_smaller(stack->a);
	pivot.last = ft_stacklast(stack->a)->nbr;
	pivot.next = stack->a->next->nbr;
	count_stack_push = stack->info.a_size - SORT_FOUR;
	if (!ft_is_ready_to_sorted_reverse())
	{
		if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size))
			ft_rotate(RA, ONE_TIME);
		else if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size - STACK_NODE))
			ft_rotate(RRA, ONE_TIME);
		else if (count_stack_push <= SORT_FOUR)
		{
			while (stack->info.a_size > SORT_FOUR)
			{
				if (pivot.first == pivot.bigger || pivot.first == pivot.smaller \
				|| pivot.next == pivot.bigger || pivot.next == pivot.smaller \
				|| pivot.last == pivot.bigger || pivot.last == pivot.smaller)
				{
					if (pivot.next == pivot.bigger || pivot.next == pivot.smaller)
						ft_swap(SA);
					else if (pivot.last == pivot.bigger || pivot.last == pivot.smaller)
						ft_rotate(RRA, ONE_TIME);
					if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
						ft_push(PB, ONE_TIME);
				}
			}
			ft_sort_four(DEFAULT);
			if (stack->info.b_size)
				ft_push(PA, stack->info.b_size);
			if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
				ft_rotate(RA, ONE_TIME);
		}
		// else if (stack->info.a_size <= SORT_FIVE && !ft_sort_target_max_nbr(stack))
		// 	return ;
	}
}
//
// static bool	ft_sort_target_max_nbr(t_stacks *stack)
// {
// 	int	penult_max_nbr;
//
// 	penult_max_nbr = stack->info.max_nbr - 1;
// 	if (stack->a->nbr == stack->info.max_nbr)
// 	{
// 		if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size))
// 			ft_rotate(RA, ONE_TIME);
// 		else if (SORT_FOUR == stack->info.a_size)
// 		{
// 			ft_rotate(RA, ONE_TIME);
// 			ft_swap(SA);
// 			// ft_push_nbr_back(stack);
// 		}
// 		else if (stack->a->next->nbr == penult_max_nbr || ft_stacklast(stack->a)->nbr == penult_max_nbr)
// 		{
// 			ft_push(PA, ONE_TIME);
// 			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
// 				ft_rotate(RRA, ONE_TIME);
// 			ft_push(PA, ONE_TIME);
// 			ft_push_nbr_back(stack);
// 		}
// 		return (true);
// 	}
// 	else if (ft_stacklast(stack->a)->nbr == stack->info.max_nbr)
// 	{
// 		ft_rotate(RRA, ONE_TIME);
// 		ft_push(PA, ONE_TIME);
// 		if (SORT_FOUR == stack->info.a_size)
// 		{
// 			penult_max_nbr = ft_peek_bigger(stack->a);
// 			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
// 			{
// 				ft_rotate(RRA, ONE_TIME);
// 				ft_push(PA, ONE_TIME);
// 			}
// 			else if (stack->a->nbr == penult_max_nbr)
// 				ft_push(PA, ONE_TIME);
// 		}
// 		ft_push_nbr_back(stack);
// 		return (true);
// 	}
// 	return (false);
// }
//
// static void	ft_push_nbr_back(t_stacks *stack)
// {
// 	ft_sort_three(DEFAULT);
// 	while (stack->info.b_size)
// 	{
// 		ft_push(PB, ONE_TIME);
// 		ft_rotate(RA, ONE_TIME);
// 	}
// }
