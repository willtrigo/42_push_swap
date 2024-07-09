/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/09 17:45:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"

static void	ft_sort_target_top_max_nbr(t_stacks *stack);

void	ft_sort_five(void)
{
	t_stacks	*stack;
	// int			last_max_nbr;

	stack = ft_stack();
	// if (stack->info.a_len == SORT_THREE)
	// 	ft_sort_three();
	// last_max_nbr = ft_peek_bigger(stack->a);
	if (stack->a->nbr == stack->info.max_nbr)
		ft_sort_target_top_max_nbr(stack);
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

static void	ft_sort_target_top_max_nbr(t_stacks *stack)
{
	int	penult_max_nbr;

	penult_max_nbr = ft_peek_bigger(stack->a->next);
	if (ft_is_sorted(stack->a->next))
		ft_rotate(RA);
	else if (stack->a->next->nbr == penult_max_nbr || ft_stacklast(stack->a)->nbr == penult_max_nbr)
	{
		ft_push(PA);
		if (ft_stacklast(stack->a)->nbr == penult_max_nbr)
			ft_rotate(RRA);
		ft_push(PA);
		ft_sort_three();
		ft_push(PB);
		ft_rotate(RA);
		ft_push(PB);
		ft_rotate(RA);
	}
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
