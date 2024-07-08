/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/08 05:30:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static bool	ft_sort_target_top(t_stacks *stack);
static void	ft_sort_target_mid(t_stacks *stack);

void	ft_sort_three(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (!ft_sort_target_top(stack))
		ft_sort_target_mid(stack);
}

static bool	ft_sort_target_top(t_stacks *stack)
{
	if (stack->a->nbr == stack->info.max_nbr)
	{
		if (ft_is_sorted(stack->a->next))
			ft_rotate(RA);
		else
		{
			ft_rotate(RA);
			ft_swap(SA);
		}
		return (true);
	}
	return (false);
}

static void	ft_sort_target_mid(t_stacks *stack)
{
	if (stack->a->next->nbr == stack->info.max_nbr)
	{
		if (ft_stacklast(stack->a)->nbr == stack->info.min_nbr)
			ft_rotate(RRA);
		else
		{
			ft_swap(SA);
			ft_rotate(RA);
		}
	}
	else
		ft_swap(SA);
}
