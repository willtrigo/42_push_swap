/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:06:24 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/05 16:19:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

void	ft_sort(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	ft_stack_normalize(STACK_DEFAULT);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
	{
		if (stack->info.a_size <= SORT_THREE)
			ft_sort_three();
		else if (stack->info.a_size == SORT_FOUR)
			ft_sort_four();
		else if (stack->info.a_size > SORT_FOUR)
			ft_sort_all();
	}
}

bool	ft_is_ready_to_sorted_reverse(void)
{
	t_stacks	*stack;
	int			push_size;

	stack = ft_stack();
	ft_stack_normalize(STACK_INDEX);
	push_size = DEFAULT;
	if (ft_is_sorted(stack->a, STACK_INDEX_REVERSE, stack->info.a_size))
	{
		while (ft_stack()->info.a_size - STACK_SIZE_FOUR)
		{
			ft_rotate_possibilities(RRA, ONE_TIME, false);
			ft_push(PB, ONE_TIME);
			push_size++;
		}
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES, false);
		ft_swap_possibilities(SA);
		ft_push(PA, push_size);
		return (true);
	}
	return (false);
}
