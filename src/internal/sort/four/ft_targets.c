/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:11:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 08:23:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/four/ft_targets.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"

void	ft_target_bigger(t_pivots pivot)
{
	if (pivot.next == (pivot.bigger - STACK_NODE))
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else if (pivot.next == (pivot.smaller + STACK_NODE) && \
		!(pivot.last == pivot.bigger - STACK_NODE))
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
	}
	else
	{
		ft_push(PB, ONE_TIME);
		ft_sort_three(DEFAULT);
		ft_push(PA, ONE_TIME);
	}
	ft_rotate(RA, ONE_TIME);
}

void	ft_target_next_bigger(t_pivots pivot)
{
	if (pivot.first == (pivot.bigger - STACK_NODE))
		ft_rotate(RA, TWO_TIMES);
	else if (((pivot.first == pivot.smaller) && \
		(pivot.last == (pivot.bigger - STACK_NODE))) \
		|| ((pivot.first == (pivot.smaller + STACK_NODE)) \
		&& (pivot.last == pivot.bigger - STACK_NODE)))
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else
	{
		ft_rotate(RA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
}

void	ft_target_penult(t_pivots pivot)
{
	if (pivot.last == pivot.bigger)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
	if (pivot.next == (pivot.smaller + STACK_NODE))
	{
		ft_swap(SA);
		if (pivot.last == pivot.smaller)
			ft_rotate(RRA, ONE_TIME);
	}
	else if (pivot.next == pivot.smaller)
	{
		if (!(pivot.last == pivot.bigger))
		{
			ft_rotate(RA, ONE_TIME);
			ft_swap(SA);
			ft_rotate(RA, ONE_TIME);
		}
	}
}

void	ft_target_next(t_pivots pivot)
{
	if (pivot.last == pivot.smaller)
		ft_rotate(RRA, ONE_TIME);
	else if (pivot.next == (pivot.bigger - STACK_NODE))
	{
		ft_rotate(RRA, TWO_TIMES);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else if (pivot.last == (pivot.bigger - STACK_NODE))
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
		ft_sort_three(DEFAULT);
		ft_push(PA, ONE_TIME);
	}
}

void	ft_target_smaller(t_pivots pivot)
{
	if (pivot.last == (pivot.smaller + STACK_NODE))
		ft_rotate(RRA, ONE_TIME);
	else if (pivot.next == (pivot.bigger - STACK_NODE))
		ft_swap(SA);
	else if (pivot.last == (pivot.bigger - STACK_NODE))
		ft_rotate(RRA, ONE_TIME);
	ft_sort_four(DEFAULT);
}
