/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/14 16:35:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/sort/ft_sort.h"

static void	ft_sort_target_top(t_stacks *stack);
static void	ft_sort_target_mid(t_stacks *stack, int nbr_smaller);

void	ft_sort_three(void)
{
	t_stacks	*stack;
	int			nbr_bigger;
	int			nbr_smaller;
	int			nbr;

	stack = ft_stack();
	nbr = ft_peek(stack->a);
	nbr_bigger = ft_peek_bigger(stack->a);
	nbr_smaller = ft_peek_smaller(stack->a);
	if (ft_is_sorted(stack->a, REVERSE, stack->info.a_size))
	{
		ft_rotate(RA, ONE_TIME);
		ft_swap(SA);
	}
	else
	{
		if (nbr == nbr_bigger)
			ft_sort_target_top(stack);
		else if (stack->a->next->nbr == nbr_bigger)
			ft_sort_target_mid(stack, nbr_smaller);
		else
			ft_swap(SA);
	}
}

static void	ft_sort_target_top(t_stacks *stack)
{
	if (ft_is_sorted(stack->a->next, DEFAULT, STACK_SIZE_TWO))
		ft_rotate(RA, ONE_TIME);
	else
	{
		ft_rotate(RA, ONE_TIME);
		ft_swap(SA);
	}
}

static void	ft_sort_target_mid(t_stacks *stack, int nbr_smaller)
{
	if (ft_stacklast(stack->a)->nbr == nbr_smaller)
		ft_rotate(RRA, ONE_TIME);
	else
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
}
