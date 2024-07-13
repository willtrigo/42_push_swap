/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/13 09:03:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_sort_target_bigger(t_stacks *stack);
static void	ft_sort_target_mid(t_stacks *stack);
static void	ft_sort_target_mid_bigger_nbr(t_stacks *stack);

void	ft_sort_four(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (stack->a->nbr == ft_peek_bigger(stack->a))
		ft_sort_target_bigger(stack);
	else
		ft_sort_target_mid(stack);
}

static void	ft_sort_target_bigger(t_stacks *stack)
{
	if (ft_is_sorted(stack->a->next, DEFAULT))
		ft_rotate(RA, ONE_TIME);
	else if (stack->a->next->nbr == (ft_peek_bigger(stack->a) - STACK_NODE))
	{
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
		if (!ft_is_sorted(stack->a, DEFAULT))
			ft_swap(SA);
	}
	else if (ft_stacklast(stack->a)->nbr \
		== (ft_peek_bigger(stack->a) - STACK_NODE))
	{
		ft_rotate(RA, ONE_TIME);
		ft_swap(SA);
	}
	else
	{
		ft_push(PB, ONE_TIME);
		ft_sort_three();
		ft_push(PA, ONE_TIME);
		ft_rotate(RA, ONE_TIME);
	}
}

static void	ft_sort_target_mid(t_stacks *stack)
{
	if (stack->a->next->nbr == ft_peek_bigger(stack->a))
		ft_sort_target_mid_bigger_nbr(stack);
	else
	{
		if (stack->a->nbr == (ft_peek_smaller(stack->a) + STACK_NODE) && stack->a->next->nbr == ft_peek_smaller(stack->a) && ft_is_sorted(stack->a->next->next, DEFAULT))
			ft_swap(SA);
		else if (stack->a->nbr == (ft_peek_smaller(stack->a) + STACK_NODE))
		{
			ft_push(PB, TWO_TIMES);
			if (ft_is_sorted(stack->a, DEFAULT))
				ft_swap(SB);
			else
				ft_rotate(RRR, ONE_TIME);
			ft_push(PA, TWO_TIMES);
		}
		else
		{
			ft_rotate(RRA, TWO_TIMES);
			ft_swap(SA);
			ft_rotate(RA, TWO_TIMES);
		}
	}
}

static void	ft_sort_target_mid_bigger_nbr(t_stacks *stack)
{
	if (stack->a->nbr == (ft_peek_bigger(stack->a) - STACK_NODE))
	{
		ft_rotate(RA, TWO_TIMES);
		if (!ft_is_sorted(stack->a, DEFAULT))
			ft_swap(SA);
	}
	else
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
}
