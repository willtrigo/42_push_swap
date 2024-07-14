/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:23:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/14 19:43:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_rotate.h"

static void	ft_sort_target_bigger(t_stacks *stack, int nbr_bigger, \
				int nbr_smaller);
static void	ft_sort_target_mid_bigger(t_stacks *stack, int nbr, \
				int nbr_bigger, int nbr_smaller);
static void	ft_sort_target_penult(t_stacks *stack, int nbr_bigger, \
				int nbr_smaller);
static void	ft_sort_target_next(t_stacks *stack, int nbr_bigger, \
				int nbr_smaller);
static void	ft_sort_target_smaller(t_stacks *stack, int nbr_bigger, \
				int nbr_smaller);

void	ft_sort_four(void)
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
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
	else
	{
		if (nbr == nbr_bigger)
			ft_sort_target_bigger(stack, nbr_bigger, nbr_smaller);
		else if (stack->a->next->nbr == nbr_bigger)
			ft_sort_target_mid_bigger(stack, nbr, nbr_bigger, nbr_smaller);
		else if (nbr == (nbr_bigger - STACK_NODE))
			ft_sort_target_penult(stack, nbr_bigger, nbr_smaller);
		else if (nbr == (nbr_smaller + STACK_NODE))
			ft_sort_target_next(stack, nbr_bigger, nbr_smaller);
		else
			ft_sort_target_smaller(stack, nbr_bigger, nbr_smaller);
	}
	if (!ft_is_sorted(stack->a, DEFAULT, stack->info.a_size))
		ft_swap(SA);
}

static void	ft_sort_target_bigger(t_stacks *stack, int nbr_bigger, \
				int nbr_smaller)
{
	int	last_node_nbr;
	int	next_node_nbr;

	last_node_nbr = ft_stacklast(stack->a)->nbr;
	next_node_nbr = stack->a->next->nbr;
	if (next_node_nbr == (nbr_bigger - STACK_NODE))
	{
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else if (next_node_nbr == (nbr_smaller + STACK_NODE) && \
		!(last_node_nbr == nbr_bigger - STACK_NODE))
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
	}
	else
	{
		ft_push(PB, ONE_TIME);
		ft_sort_three();
		ft_push(PA, ONE_TIME);
	}
	ft_rotate(RA, ONE_TIME);
}

static void	ft_sort_target_mid_bigger(t_stacks *stack, int nbr, \
				int nbr_bigger, int nbr_smaller)
{
	int	last_node_nbr;

	last_node_nbr = ft_stacklast(stack->a)->nbr;
	if (nbr == (nbr_bigger - STACK_NODE))
		ft_rotate(RA, TWO_TIMES);
	else if (((nbr == nbr_smaller) && \
		(last_node_nbr == (nbr_bigger - STACK_NODE))) \
		|| ((nbr == (nbr_smaller + STACK_NODE)) \
		&& (last_node_nbr == nbr_bigger - STACK_NODE)))
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

static void	ft_sort_target_penult(t_stacks *stack, \
				int nbr_bigger, int nbr_smaller)
{
	int	last_node_nbr;
	int	next_node_nbr;

	last_node_nbr = ft_stacklast(stack->a)->nbr;
	next_node_nbr = stack->a->next->nbr;
	if (last_node_nbr == nbr_bigger)
	{
		ft_rotate(RRA, ONE_TIME);
		ft_swap(SA);
		ft_rotate(RA, TWO_TIMES);
	}
	if (next_node_nbr == (nbr_smaller + STACK_NODE))	
	{
		ft_swap(SA);
		if (last_node_nbr == nbr_smaller)
			ft_rotate(RRA, ONE_TIME);
	}
	else if (next_node_nbr == nbr_smaller)
	{
		if (!(last_node_nbr == nbr_bigger))
		{
			ft_rotate(RA, ONE_TIME);
			ft_swap(SA);
			ft_rotate(RA, ONE_TIME);
		}
	}
}

static void	ft_sort_target_next(t_stacks *stack, \
				int nbr_bigger, int nbr_smaller)
{
	int	last_node_nbr;
	int	next_node_nbr;

	last_node_nbr = ft_stacklast(stack->a)->nbr;
	next_node_nbr = stack->a->next->nbr;
	if (last_node_nbr == nbr_smaller)
		ft_rotate(RRA, ONE_TIME);
	else if (next_node_nbr == (nbr_bigger - STACK_NODE))	
	{
		ft_rotate(RRA, TWO_TIMES);
		ft_swap(SA);
		ft_rotate(RA, ONE_TIME);
	}
	else if (last_node_nbr == (nbr_bigger - STACK_NODE))
	{
		ft_swap(SA);
		ft_push(PB, ONE_TIME);
		ft_sort_three();
		ft_push(PA, ONE_TIME);
	}
}

static void	ft_sort_target_smaller(t_stacks *stack, \
				int nbr_bigger, int nbr_smaller)
{
	int	last_node_nbr;
	int	next_node_nbr;

	last_node_nbr = ft_stacklast(stack->a)->nbr;
	next_node_nbr = stack->a->next->nbr;
	if (last_node_nbr == (nbr_smaller + STACK_NODE))
		ft_rotate(RRA, ONE_TIME);
	else if (next_node_nbr == (nbr_bigger - STACK_NODE))	
	{
		ft_swap(SA);
		ft_sort_four();
		return ;
	}
	else if (last_node_nbr == (nbr_bigger - STACK_NODE))
	{
		ft_rotate(RRA, ONE_TIME);
		ft_sort_four();
		return ;
	}
}
