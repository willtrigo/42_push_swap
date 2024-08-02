/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:44:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/02 03:53:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_cost.h"
#include "internal/sort/all/ft_return_nbrs.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/operation/ft_swap.h"

void	ft_return_sorted_all(t_stacks *stack, t_pivots *pivot)
{
	if (stack->info.b_size && stack->a->nbr + STACK_SIZE_TWO \
		== stack->a->next->nbr)
		ft_return_nbr_between(stack, stack->a->nbr + STACK_NODE, pivot);
	else if (stack->info.b_size && stack->a->nbr + STACK_NODE \
		== stack->a->next->nbr)
		ft_return_nbr(stack, stack->a->nbr - STACK_NODE, pivot);
}

void	ft_return_nbr_between(t_stacks *stack, int value, t_pivots *pivot)
{
	t_cost	direction;

	direction = ft_return_best_cost(value, STACK_B, false, stack->info.b_size);
	if (stack->b->nbr == value)
	{
		ft_push(PA, ONE_TIME);
		ft_swap_possibilities(SA);
	}
	else if (direction == TOP)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (direction == BOT)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
		if (stack->b->nbr < stack->b->next->nbr)
			ft_swap_possibilities(SB);
	}
	ft_return_sorted_all(stack, pivot);
}

void	ft_return_nbr(t_stacks *stack, int value, t_pivots *pivot)
{
	t_cost	direction;

	direction = ft_return_best_cost(value, STACK_B, true, stack->info.b_size);
	if (stack->b->nbr == value || stack->b->nbr == value - STACK_NODE)
		ft_push(PA, ONE_TIME);
	else if (direction == TOP)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (direction == BOT)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
		if (stack->b->nbr < stack->b->next->nbr)
			ft_swap_possibilities(SB);
	}
	ft_return_sorted_all(stack, pivot);
}
