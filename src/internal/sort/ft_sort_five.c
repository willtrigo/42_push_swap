/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/10 11:47:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
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

void	ft_sort_five(void)
{
	t_stacks	*stack;
	// int			last_max_nbr;

	stack = ft_stack();
	// if (stack->info.a_len == SORT_THREE)
	// 	ft_sort_three();
	// last_max_nbr = ft_peek_bigger(stack->a);
	if (!ft_sort_target_max_nbr(stack))
		 return ;
	// else if (stack->a->nbr == last_max_nbr)
	// {
	// 	if (ft_is_sorted(stack->a->next))
	// 	{
	// 		ft_rotate(RA);
	// 		if (stack->b)
	// 		{
	// 			ft_push(PB);
	// 			ft_rotate(RA);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		ft_push(PA);
	// 		ft_sort_three();
	// 		ft_push(PB);
	// 		ft_rotate(RA);
	// 		ft_push(PB);
	// 		ft_rotate(RA);
	// 	}
	// }
		// ft_swap(SA);
}

static bool	ft_sort_target_max_nbr(t_stacks *stack)
{
	int	penult_max_nbr;

	penult_max_nbr = ft_peek_bigger(stack->a->next);
	if (stack->a->nbr == stack->info.max_nbr)
	{
		if (ft_is_sorted(stack->a->next))
			ft_rotate(RA);
		else if (SORT_FOUR == stack->info.a_len)
		{
			ft_push(PA);
			ft_push_nbr_back(stack);
		}
		else if (stack->a->next->nbr == penult_max_nbr || ft_stacklast(stack->a)->nbr == penult_max_nbr)
		{
			ft_push(PA);
			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
				ft_rotate(RRA);
			ft_push(PA);
			ft_push_nbr_back(stack);
		}
		return (true);
	}
	// else if (ft_stacklast(stack->a)->nbr == stack->info.max_nbr && SORT_FOUR == stack->info.a_len)
	// {
	// 	ft_rotate(RRA);
	// 	ft_push(PA);
	// 	ft_push_nbr_back(stack);
	// 	return (true);
	// }
	else if (ft_stacklast(stack->a)->nbr == stack->info.max_nbr)
	{
		ft_rotate(RRA);
		ft_push(PA);
		if (SORT_FOUR == stack->info.a_len)
		{
			penult_max_nbr = ft_peek_bigger(stack->a);
			if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
			{
				ft_rotate(RRA);
				ft_push(PA);
			}
			else if (stack->a->nbr == penult_max_nbr)
				ft_push(PA);
		}
		ft_push_nbr_back(stack);
		return (true);
	}
	return (false);
	// else if (ft_is_sorted(stack->a->next))
	// {
	// 	ft_push(PA);
	// 	ft_rotate(RA);
	// 	ft_push(PB);
	// 	ft_rotate(RA);
	// }
	// else
	// {
	// 	ft_push(PA);
	// 	if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
	// 	{
	// 		ft_rotate(RRA);
	// 		ft_push(PA);
	// 	}
	// 	ft_sort_five();
	// }
}

static void	ft_push_nbr_back(t_stacks *stack)
{
	ft_sort_three();
	while (stack->info.b_len)
	{
		ft_push(PB);
		ft_rotate(RA);
	}
}
