/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 05:38:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/04 08:58:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/ft_stack.h"

int	ft_pop(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_nbr = (*stack)->nbr;
	if ((*stack)->next && !(*stack)->prev)
	{
		temp_stack = (*stack)->next;
		free(*stack);
		*stack = temp_stack;
		(*stack)->prev = NULL;
	}
	else if ((*stack)->prev &&!(*stack)->next)
	{
		(*stack)->prev->next = NULL;
		free(*stack);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
	return (temp_nbr);
}
