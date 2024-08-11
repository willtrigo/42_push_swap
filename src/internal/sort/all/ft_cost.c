/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:23:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/11 02:33:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/all/ft_cost.h"

static int	ft_get_nbr_cost(int value, t_stack_targets target);
static int	ft_get_nbr_cost_reverse(int value, t_stack_targets target);

t_cost	ft_return_best_cost(int value, t_stack_targets target, bool is_between)
{
	int	cost;
	int	cost_reverse;
	int	cost_next;
	int	cost_next_reverse;

	cost_next = DEFAULT;
	cost_next_reverse = DEFAULT;
	cost = ft_get_nbr_cost(value, target);
	cost_reverse = ft_get_nbr_cost_reverse(value, target);
	if (target == STACK_B && cost != DEFAULT && is_between \
		&& ft_stack()->info.b_size > STACK_SIZE_TWO)
	{
		cost_next = ft_get_nbr_cost(value - STACK_NODE, target);
		cost_next_reverse = ft_get_nbr_cost_reverse(value - STACK_NODE, target);
		if (cost > cost_next)
			cost = cost_next;
		if (cost_reverse > cost_next_reverse)
			cost_reverse = cost_next_reverse;
	}
	if (cost > cost_reverse)
		return (BOT);
	return (TOP);
}

void	ft_push_number_to_b_top(t_stacks *stack, t_pivots *pivot)
{
	t_cost	direction;

	direction = ft_return_best_cost(pivot->mid_static \
		+ (pivot->mid_static * pivot->mid_time), STACK_A, false);
	if (direction == TOP && stack->a->nbr > pivot->mid_static \
		+ (pivot->mid_static * pivot->mid_time))
		ft_rotate_possibilities(RB, ONE_TIME, true);
	else
		ft_rotate_possibilities(RB, ONE_TIME, false);
}

void	ft_push_number_to_b_bot(t_stacks *stack, t_pivots *pivot)
{
	t_cost	direction;

	direction = ft_return_best_cost(pivot->mid_static \
		+ (pivot->mid_static * pivot->mid_time), STACK_A, false);
	if (direction == BOT && stack->a->nbr > pivot->mid_static \
		+ (pivot->mid_static * pivot->mid_time))
		ft_rotate_possibilities(RRB, ONE_TIME, true);
	else
		ft_rotate_possibilities(RRB, ONE_TIME, false);
}

static int	ft_get_nbr_cost(int value, t_stack_targets target)
{
	t_stack	*temp_stack;
	int		cost;

	cost = DEFAULT;
	if (target == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack->next)
	{
		if (target == STACK_A && temp_stack->nbr < value)
			break ;
		else if (target == STACK_B && temp_stack->nbr == value)
			break ;
		cost++;
		temp_stack = temp_stack->next;
	}
	return (cost);
}

static int	ft_get_nbr_cost_reverse(int value, t_stack_targets target)
{
	t_stack	*temp_stack;
	int		cost;

	cost = DEFAULT;
	if (target == STACK_A)
		temp_stack = ft_stacklast(ft_stack()->a);
	else
		temp_stack = ft_stacklast(ft_stack()->b);
	while (temp_stack->prev)
	{
		if (target == STACK_A && temp_stack->nbr < value)
			break ;
		else if (target == STACK_B && temp_stack->nbr == value)
			break ;
		cost++;
		temp_stack = temp_stack->prev;
	}
	return (cost);
}
