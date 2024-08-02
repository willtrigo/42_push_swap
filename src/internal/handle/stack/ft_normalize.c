/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:23:55 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/02 00:06:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_default.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"

static void	ft_set_value(int value, t_stack_targets target);
static void	ft_set_normalize(t_stack_targets target);
static void	ft_normalize_bigger_nbr(int temp_bigger_nbr, int stack_size, \
				t_stack_targets target);
static void	ft_normalize_others_nbrs(int temp_bigger_nbr, int stack_size, \
				t_stack_targets target, int temp_check_bigger_nbr);

void	ft_stack_normalize(t_type type)
{
	ft_set_value(INIT, STACK_A);
	ft_set_normalize(STACK_A);
	if (ft_stack()->info.b_size)
	{
		ft_set_value(INIT, STACK_B);
		ft_set_normalize(STACK_B);
	}
	if (type == STACK_DEFAULT)
		ft_set_value(DEFAULT, STACK_A);
}

static void	ft_set_value(int value, t_stack_targets target)
{
	t_stack	*temp_stack;

	if (target == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack)
	{
		if (value == INIT)
			temp_stack->index = INIT;
		else
			temp_stack->nbr = temp_stack->index;
		temp_stack = temp_stack->next;
	}
}

static void	ft_set_normalize(t_stack_targets target)
{
	int	temp_bigger_nbr;
	int	stack_size;
	int	temp_check_bigger_nbr;

	if (target == STACK_A)
	{
		temp_bigger_nbr = ft_peek_bigger(ft_stack()->a, STACK_NBR);
		stack_size = ft_stack()->info.a_size;
	}
	else
	{
		temp_bigger_nbr = ft_peek_bigger(ft_stack()->b, STACK_NBR);
		stack_size = ft_stack()->info.b_size;
	}
	ft_normalize_bigger_nbr(temp_bigger_nbr, stack_size, target);
	temp_check_bigger_nbr = INT_MIN;
	ft_normalize_others_nbrs(temp_bigger_nbr, stack_size, target, \
		temp_check_bigger_nbr);
}

static void	ft_normalize_bigger_nbr(int temp_bigger_nbr, int stack_size, \
				t_stack_targets target)
{
	t_stack	*temp_stack;

	if (target == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack)
	{
		if (temp_stack->nbr == temp_bigger_nbr)
			break ;
		temp_stack = temp_stack->next;
	}
	temp_stack->index = stack_size - 1;
}

static void	ft_normalize_others_nbrs(int temp_bigger_nbr, int stack_size, \
				t_stack_targets target, int temp_check_bigger_nbr)
{
	t_stack	*temp_stack;
	t_stack	*temp_stack_bigger;

	temp_stack_bigger = NULL;
	while (--stack_size)
	{
		if (target == STACK_A)
			temp_stack = ft_stack()->a;
		else
			temp_stack = ft_stack()->b;
		while (temp_stack)
		{
			if (temp_stack->index == INIT && temp_check_bigger_nbr \
				< temp_stack->nbr && temp_stack->nbr < temp_bigger_nbr)
			{
				temp_check_bigger_nbr = temp_stack->nbr;
				temp_stack_bigger = temp_stack;
			}
			temp_stack = temp_stack->next;
		}
		temp_stack_bigger->index = stack_size - 1;
		temp_bigger_nbr = temp_stack_bigger->nbr;
		temp_check_bigger_nbr = INT_MIN;
	}
}
