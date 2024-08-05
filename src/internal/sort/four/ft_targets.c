/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:11:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/05 16:44:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"

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
		ft_rotate_possibilities(RRA, ONE_TIME, false);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME, false);
	}
	else if (pivot->next == pivot->bigger - STACK_NODE)
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES, false);
	}
	else
	{
		ft_rotate_possibilities(RA, ONE_TIME, false);
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
		ft_rotate_possibilities(RRA, ONE_TIME, false);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->next == pivot->bigger)
		ft_rotate_possibilities(RA, TWO_TIMES, false);
	else
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES, false);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME, false);
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
		ft_rotate_possibilities(RRA, ONE_TIME, false);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot->next == pivot->bigger)
	{
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME, false);
	}
	else
	{
		ft_rotate_possibilities(RA, TWO_TIMES, false);
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, ONE_TIME, false);
	}
}
