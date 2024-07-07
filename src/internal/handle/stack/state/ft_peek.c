/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:48:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/07 06:37:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/state/ft_peek.h"

int	ft_peek(t_stack *stack)
{
	return (stack->nbr);
}

int	ft_peek_bigger(t_stack *stack)
{
	t_stack	*temp_stack;
	int		bigger;
	int		next_value;

	temp_stack = stack;
	bigger = ft_peek(temp_stack);
	while (temp_stack->next)
	{
		next_value = ft_peek(temp_stack->next);
		if (bigger < next_value)
			bigger = next_value;
		temp_stack = temp_stack->next;
	}
	return (bigger);
}

int	ft_peek_smaller(t_stack *stack)
{
	t_stack	*temp_stack;
	int		smaller;
	int		next_value;

	temp_stack = stack;
	smaller = ft_peek(temp_stack);
	while (temp_stack->next)
	{
		next_value = ft_peek(temp_stack->next);
		if (smaller > next_value)
			smaller = next_value;
		temp_stack = temp_stack->next;
	}
	return (smaller);
}
