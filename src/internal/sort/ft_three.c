/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/24 05:52:44 by dande-je         ###   ########.fr       */
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

#include "ft_non_standard/ft_non_standard.h"
void	ft_sort_three(int type)
{
	t_stacks	*stack;
	t_pivots	pivot;

	stack = ft_stack();
	ft_stack_normalize(PEEK_INDEX);
	ft_putendl_fd("three normalize stack A\n", STDERR_FILENO);
	ft_print_stack(STACK_A);
	if (type == DEFAULT)
		ft_set_pivots(stack->a, &pivot);
	else
		ft_set_pivots(stack->b, &pivot);
	if (type == DEFAULT)
		ft_run_sort_three(stack, pivot);
	else
		ft_run_sort_three_reverse(stack, pivot);
	ft_putendl_fd("end normalize stack A\n", STDERR_FILENO);
	ft_print_stack(STACK_A);
}

static void	ft_run_sort_three(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->a, REVERSE, stack->info.a_size))
		ft_rotate(RA, ONE_TIME);
	else
	{
		if (pivot.first == pivot.bigger)
			ft_rotate(RA, ONE_TIME);
		else if (pivot.next == pivot.bigger)
		{
			if (pivot.last == pivot.smaller)
				ft_rotate(RRA, ONE_TIME);
			else
			{
				ft_swap(SA);
				ft_rotate(RA, ONE_TIME);
			}
		}
	}
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

static void	ft_run_sort_three_reverse(t_stacks *stack, t_pivots pivot)
{
	if (ft_is_sorted(stack->b, DEFAULT, stack->info.b_size))
		ft_rotate(RB, ONE_TIME);
	else
	{
		if (pivot.first == pivot.smaller)
			ft_rotate(RB, ONE_TIME);
		else if (pivot.next == pivot.smaller)
		{
			if (pivot.last == pivot.bigger)
				ft_rotate(RRB, ONE_TIME);
			else
			{
				ft_swap(SB);
				ft_rotate(RB, ONE_TIME);
			}
		}
	}
	if (!ft_is_sorted(stack->b, REVERSE, stack->info.b_size))
		ft_swap(SB);
}
