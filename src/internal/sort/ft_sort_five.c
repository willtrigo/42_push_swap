/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/08 03:41:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"

static void	ft_sort_target_max_nbr(t_stacks *stack);

void	ft_sort_five(void)
{
	t_stacks	*stack;
	int			last_max_nbr;

	stack = ft_stack();
	last_max_nbr = ft_peek_bigger(stack->a);
	if (stack->a->nbr == stack->info.max_nbr)
		ft_sort_target_max_nbr(stack);
	else if (stack->a->nbr == last_max_nbr)
	{
		if (ft_is_sorted(stack->a->next))
		{
			ft_rotate(RA);
			if (stack->b)
			{
				ft_push(PB);
				ft_rotate(RA);
			}
		}
		else
		{
			ft_push(PA);
			ft_sort_three();
			ft_push(PB);
			ft_rotate(RA);
			ft_push(PB);
			ft_rotate(RA);
		}
	}
		// ft_swap(SA);
}

static void	ft_sort_target_max_nbr(t_stacks *stack)
{
	if (ft_is_sorted(stack->a->next))
		ft_rotate(RA);
	else if (ft_is_sorted(stack->a->next->next))
	{
		ft_push(PA);
		ft_rotate(RA);
		ft_push(PB);
		ft_rotate(RA);
	}
	else
	{
		ft_push(PA);
		ft_sort_five();
	}
}
