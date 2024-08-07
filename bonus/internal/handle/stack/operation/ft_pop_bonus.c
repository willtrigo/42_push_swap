/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:03:56 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 05:06:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/operation/ft_pop_bonus.h"

static void	ft_connect_stack(t_stack **stack, t_stack *temp_stack);

int	ft_pop(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_nbr = (*stack)->nbr;
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
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
