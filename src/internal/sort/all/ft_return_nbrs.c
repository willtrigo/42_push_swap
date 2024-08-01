/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:44:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/01 04:49:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_all.h"
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
	int	cost;
	int	cost_reverse;

	cost = ft_get_cost(value);
	cost_reverse = stack->info.b_size - ft_get_cost(value);
	if (cost > DEFAULT && cost <= cost_reverse)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (cost > cost_reverse)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
		if (stack->b->nbr < stack->b->next->nbr)
			ft_swap_possibilities(SB);
	}
	else
	{
		ft_push(PA, ONE_TIME);
		ft_swap_possibilities(SA);
	}
	ft_return_sorted_all(stack, pivot);
}

void	ft_return_nbr(t_stacks *stack, int value, t_pivots *pivot)
{
	int	cost;
	int	cost_reverse;

	cost = ft_get_cost(value);
	cost_reverse = stack->info.b_size - ft_get_cost(value);
	if (cost > DEFAULT && cost <= cost_reverse)
	{
		ft_rotate_possibilities(RB, ONE_TIME);
	}
	else if (cost > cost_reverse)
	{
		ft_rotate_possibilities(RRB, ONE_TIME);
		if (stack->b->nbr < stack->b->next->nbr)
			ft_swap_possibilities(SB);
	}
	else
		ft_push(PA, ONE_TIME);
	ft_return_sorted_all(stack, pivot);
}
