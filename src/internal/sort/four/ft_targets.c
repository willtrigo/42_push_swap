/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:11:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/18 10:47:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/sort/ft_sort.h"

void	ft_target_bigger(t_pivots pivot)
{
	if (pivot.next == pivot.smaller)
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot.last == pivot.smaller)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else if (pivot.next == pivot.bigger - STACK_NODE)
	{
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
	else
		ft_rotate(RA, ONE_TIME);
}

void	ft_target_penult(t_pivots pivot)
{
	if (pivot.next == pivot.smaller)
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot.last == pivot.smaller)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot.next == pivot.bigger)
		ft_rotate(RA, TWO_TIMES);
	else
	{
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
}

void	ft_target_small_mid(t_pivots pivot)
{
	if (pivot.next == pivot.smaller)
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot.last == pivot.smaller)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_push(PB, ONE_TIME);
	}
	else if (pivot.next == pivot.bigger)
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else
	{
		ft_rotate(RA, TWO_TIMES);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
}
