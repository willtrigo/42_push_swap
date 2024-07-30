/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:11:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 02:38:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/sort/ft_sort.h"

static void	ft_target_bigger(t_pivots *pivot);
static void	ft_target_penult(t_pivots *pivot);
static void	ft_target_small_mid(t_pivots *pivot);

void	ft_targets(t_pivots *pivot)
{
	if (pivot->first == pivot->smaller)
		ft_push(PB, ONE_TIME);
	else if (pivot->first == pivot->smaller + STACK_NODE)
		ft_target_small_mid(pivot);
	else if (pivot->first == pivot->bigger - STACK_NODE)
		ft_target_penult(pivot);
	else if (pivot->first == pivot->bigger)
		ft_target_bigger(pivot);
	ft_set_pivots(ft_stack()->a, pivot);
	ft_stack_normalize(STACK_INDEX);
	if (ft_stack()->info.a_size <= SORT_THREE)
		ft_sort_three();
	if (ft_stack()->info.b_size && ft_stack()->info.a_size == STACK_SIZE_THREE)
		ft_push(PA, ONE_TIME);
}

static void	ft_target_bigger(t_pivots *pivot)
{
	if (pivot->next == pivot->smaller)
	{
		ft_swap_possibilities(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->last == pivot->smaller)
	{
		ft_rotate_possibilities(RRA, ONE_TIME);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
	}
	else if (pivot->next == pivot->bigger - STACK_NODE)
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES);
	}
	else
	{
		ft_rotate_possibilities(RA, ONE_TIME);
		ft_swap_possibilities(SA);
	}
}

static void	ft_target_penult(t_pivots *pivot)
{
	if (pivot->next == pivot->smaller)
	{
		ft_swap_possibilities(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->last == pivot->smaller)
	{
		ft_rotate_possibilities(RRA, ONE_TIME);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->next == pivot->bigger)
		ft_rotate_possibilities(RA, TWO_TIMES);
	else
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
	}
}

static void	ft_target_small_mid(t_pivots *pivot)
{
	if (pivot->next == pivot->smaller)
	{
		ft_swap_possibilities(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->last == pivot->smaller)
	{
		ft_rotate_possibilities(RRA, ONE_TIME);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->next == pivot->bigger)
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
	}
	else
	{
		ft_rotate_possibilities(RA, TWO_TIMES);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME);
	}
}
