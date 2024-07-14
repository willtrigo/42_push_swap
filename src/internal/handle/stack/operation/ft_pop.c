/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 05:38:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/14 08:43:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/operation/ft_pop.h"
#include "internal/handle/stack/ft_stack.h"

static void	ft_connect_stack(t_stack **stack, t_stack *temp_stack);

int	ft_pop(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_nbr = (*stack)->index;
	temp_stack = NULL;
	ft_connect_stack(stack, temp_stack);
	return (temp_nbr);
}

static void	ft_connect_stack(t_stack **stack, t_stack *temp_stack)
{
	if ((*stack)->next && !(*stack)->prev)
	{
		temp_stack = (*stack)->next;
		free(*stack);
		*stack = temp_stack;
		(*stack)->prev = NULL;
	}
	else if ((*stack)->prev && !(*stack)->next)
	{
		(*stack)->prev->next = NULL;
		free(*stack);
	}
	else if ((*stack)->next && (*stack)->prev)
	{
		temp_stack = (*stack)->next;
		free(*stack);
		*stack = temp_stack;
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
