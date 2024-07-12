/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/12 11:11:34 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"

static bool	ft_sort_target_max_nbr(t_stacks *stack);
static void	ft_push_nbr_back(t_stacks *stack);

void	ft_sort_all(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (stack->info.a_size <= SORT_FIVE && !ft_sort_target_max_nbr(stack))
		 return ;
}

static bool	ft_sort_target_max_nbr(t_stacks *stack)
{
	int	penult_max_nbr;

	penult_max_nbr = stack->info.max_nbr - 1;
	if (stack->a->nbr == stack->info.max_nbr)
	{
		if (ft_is_sorted(stack->a->next, DEFAULT))
			ft_rotate(RA, ONE_TIME);
		else if (SORT_FOUR == stack->info.a_size)
		{
			ft_rotate(RA, ONE_TIME);
			ft_swap(SA);
			// ft_push_nbr_back(stack);
		}
		else if (stack->a->next->nbr == penult_max_nbr || ft_stacklast(stack->a)->nbr == penult_max_nbr)
		{
			ft_push(PA, ONE_TIME);
			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
				ft_rotate(RRA, ONE_TIME);
			ft_push(PA, ONE_TIME);
			ft_push_nbr_back(stack);
		}
		return (true);
	}
	else if (ft_stacklast(stack->a)->nbr == stack->info.max_nbr)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_push(PA, ONE_TIME);
		if (SORT_FOUR == stack->info.a_size)
		{
			penult_max_nbr = ft_peek_bigger(stack->a);
			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
			{
				ft_rotate(RRA, ONE_TIME);
				ft_push(PA, ONE_TIME);
			}
			else if (stack->a->nbr == penult_max_nbr)
				ft_push(PA, ONE_TIME);
		}
		ft_push_nbr_back(stack);
		return (true);
	}
	return (false);
}

static void	ft_push_nbr_back(t_stacks *stack)
{
	ft_sort_three();
	while (stack->info.b_size)
	{
		ft_push(PB, ONE_TIME);
		ft_rotate(RA, ONE_TIME);
	}
}
