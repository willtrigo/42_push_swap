/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:08:48 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/14 13:31:34 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_sort_target_top(t_stacks *stack);
static void	ft_sort_target_mid(t_stacks *stack);

void	ft_sort_three_reverse(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (!ft_is_sorted(stack->b, REVERSE, stack->info.a_size))
	{
		if (stack->b->nbr == ft_peek_smaller(stack->b))
			ft_sort_target_top(stack);
		else if (stack->b->next->nbr == ft_peek_smaller(stack->b))
			ft_sort_target_mid(stack);
		else
			ft_swap(SB);
	}
}

static void	ft_sort_target_top(t_stacks *stack)
{
	if (stack->b->next->nbr == ft_peek_bigger(stack->b))
		ft_rotate(RB, ONE_TIME);
	else
	{
		ft_rotate(RB, ONE_TIME);
		ft_swap(SB);
	}
}

static void	ft_sort_target_mid(t_stacks *stack)
{
	if (stack->b->nbr == ft_peek_bigger(stack->b))
		ft_rotate(RB, ONE_TIME);
	// else
	// {
	// 	ft_swap(SB);
	// 	ft_rotate(RB, ONE_TIME);
	// }
}
