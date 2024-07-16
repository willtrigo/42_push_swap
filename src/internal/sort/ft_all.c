/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 19:23:57 by dande-je         ###   ########.fr       */
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
		if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size - STACK_NODE))
			ft_rotate(RA, ONE_TIME);
		else if (ft_is_sorted(stack->a, DEFAULT, stack->info.a_size - STACK_NODE))
			ft_rotate(RRA, ONE_TIME);




		pivot.first = ft_peek(stack->a);
		pivot.next = stack->a->next->nbr;
		pivot.last = ft_stacklast(stack->a)->nbr;
		if (count_stack_push <= SORT_FOUR && !ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		{
			if (pivot.first - STACK_NODE == pivot.next && pivot.first != pivot.bigger)
				ft_swap(SA);




			pivot.first = ft_peek(stack->a);
			pivot.next = stack->a->next->nbr;
			pivot.last = ft_stacklast(stack->a)->nbr;
			// if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
			// {
			if (pivot.first == pivot.smaller || pivot.first == pivot.bigger)
			{
				if (ft_is_sorted(stack->a->next, DEFAULT, stack->info.a_size - STACK_NODE))
					ft_rotate(RA, ONE_TIME);
				else
					ft_push(PB, ONE_TIME);
			}
			// }
			else if (pivot.last == pivot.smaller || pivot.next == pivot.smaller)
			{
				if (pivot.last == pivot.smaller)
					ft_rotate(RRA, ONE_TIME);
				else if (pivot.next == pivot.smaller)
					ft_swap(SA);
				ft_push(PB, ONE_TIME);
			}
			else if (pivot.last == pivot.bigger || pivot.next == pivot.bigger)
			{
				if (pivot.last == pivot.bigger)
					ft_rotate(RRA, ONE_TIME);
				else if (pivot.next == pivot.bigger)
					ft_swap(SA);
				ft_push(PB, ONE_TIME);
			}
		// 	}
			// if (stack->info.a_size <= SORT_FOUR)
			// 	ft_sort_four(DEFAULT);
		// 	if (stack->info.b_size)
		// 		ft_push(PA, stack->info.b_size);
		// 	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		// 		ft_rotate(RA, ONE_TIME);
		// 	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		// 		ft_sort_all();
		}
	}
}
