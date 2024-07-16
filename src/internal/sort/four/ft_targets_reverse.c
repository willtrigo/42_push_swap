/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:12:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 09:11:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/state/ft_state.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/four/ft_targets_reverse.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"

void	ft_target_smaller_reverse(t_pivots pivot)
{
	if (pivot.next == (pivot.smaller + STACK_NODE))
	{
		ft_swap(SB);
		ft_rotate(RB, ONE_TIME);
	}
	else if (pivot.next == (pivot.bigger - STACK_NODE) && \
		!(pivot.last == pivot.smaller + STACK_NODE))
	{
		ft_rotate(RRB, ONE_TIME);
		ft_swap(SB);
	}
	else
	{
		ft_push(PB, ONE_TIME);
		ft_sort_three(REVERSE);
		ft_push(PB, ONE_TIME);
	}
	ft_rotate(RB, ONE_TIME);
}

void	ft_target_next_smaller_reverse(t_pivots pivot)
{
	if (pivot.first == (pivot.smaller + STACK_NODE))
		ft_rotate(RB, TWO_TIMES);
	else if (((pivot.first == pivot.bigger) && \
		(pivot.last == (pivot.smaller + STACK_NODE))) \
		|| ((pivot.first == (pivot.bigger - STACK_NODE)) \
		&& (pivot.last == pivot.smaller + STACK_NODE)))
	{
		ft_swap(SB);
		ft_rotate(RB, ONE_TIME);
	}
	else
	{
		ft_rotate(RB, ONE_TIME);
		ft_swap(SB);
		ft_rotate(RB, TWO_TIMES);
	}
}

void	ft_target_penult_reverse(t_pivots pivot)
{
	if (pivot.last == pivot.smaller)
	{
		ft_rotate(RRB, ONE_TIME);
		ft_swap(SB);
		ft_rotate(RB, TWO_TIMES);
	}
	if (pivot.next == (pivot.bigger - STACK_NODE))
	{
		ft_swap(SB);
		if (pivot.last == pivot.bigger)
			ft_rotate(RRB, ONE_TIME);
	}
	else if (pivot.next == pivot.bigger)
	{
		if (!(pivot.last == pivot.smaller))
		{
			ft_rotate(RB, ONE_TIME);
			ft_swap(SB);
			ft_rotate(RB, ONE_TIME);
		}
	}
}

void	ft_target_next_reverse(t_pivots pivot)
{
	if (pivot.last == pivot.bigger)
		ft_rotate(RRB, ONE_TIME);
	else if (pivot.next == (pivot.smaller + STACK_NODE))
	{
		ft_rotate(RRB, TWO_TIMES);
		ft_swap(SB);
		ft_rotate(RB, ONE_TIME);
	}
	else if (pivot.last == (pivot.smaller + STACK_NODE))
	{
		ft_swap(SB);
		ft_push(PA, ONE_TIME);
		ft_sort_three(REVERSE);
		ft_push(PB, ONE_TIME);
	}
}

void	ft_target_bigger_reverse(t_pivots pivot)
{
	if (pivot.last == (pivot.bigger - STACK_NODE))
		ft_rotate(RRB, ONE_TIME);
	else if (pivot.next == (pivot.smaller + STACK_NODE))
		ft_swap(SB);
	else if (pivot.last == (pivot.smaller + STACK_NODE))
		ft_rotate(RRB, ONE_TIME);
	ft_sort_four(REVERSE);
}
