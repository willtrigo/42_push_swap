/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:25:52 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/11 16:08:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_default.h"
#include "internal/handle/stack/ft_stack_bonus.h"
#include "internal/handle/stack/state/ft_peek_bonus.h"

static void	ft_set_value(int value);
static void	ft_set_normalize(void);
static void	ft_normalize_bigger_nbr(int temp_bigger_nbr, int stack_size);
static void	ft_normalize_others_nbrs(int temp_bigger_nbr, int stack_size, \
				int temp_check_bigger_nbr);

void	ft_stack_normalize(void)
{
	ft_set_value(INIT);
	ft_set_normalize();
	ft_set_value(DEFAULT);
}

static void	ft_set_value(int value)
{
	t_stack	*temp_stack;

	temp_stack = ft_stack()->a;
	while (temp_stack)
	{
		if (value == INIT)
			temp_stack->index = INIT;
		else
			temp_stack->nbr = temp_stack->index;
		temp_stack = temp_stack->next;
	}
}

static void	ft_set_normalize(void)
{
	int	temp_bigger_nbr;
	int	stack_size;
	int	temp_check_bigger_nbr;

	temp_bigger_nbr = ft_peek_bigger(ft_stack()->a, STACK_NBR);
	stack_size = ft_stack()->info.a_size;
	ft_normalize_bigger_nbr(temp_bigger_nbr, stack_size);
	temp_check_bigger_nbr = INT_MIN;
	ft_normalize_others_nbrs(temp_bigger_nbr, stack_size, \
		temp_check_bigger_nbr);
}

static void	ft_normalize_bigger_nbr(int temp_bigger_nbr, int stack_size)
{
	t_stack	*temp_stack;

	temp_stack = ft_stack()->a;
	while (temp_stack)
	{
		if (temp_stack->nbr == temp_bigger_nbr)
			break ;
		temp_stack = temp_stack->next;
	}
	temp_stack->index = stack_size - 1;
}

static void	ft_normalize_others_nbrs(int temp_bigger_nbr, int stack_size, \
				int temp_check_bigger_nbr)
{
	t_stack	*temp_stack;
	t_stack	*temp_stack_bigger;

	temp_stack_bigger = NULL;
	while (--stack_size)
	{
		temp_stack = ft_stack()->a;
		while (temp_stack)
		{
			if (temp_stack->index == INIT && temp_check_bigger_nbr \
				<= temp_stack->nbr && temp_stack->nbr <= temp_bigger_nbr)
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
