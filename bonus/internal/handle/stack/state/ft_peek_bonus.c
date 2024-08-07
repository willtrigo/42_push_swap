/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:27:46 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:30:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/state/ft_peek_bonus.h"

int	ft_peek(t_stack *stack, t_type type)
{
	if (type == STACK_NBR)
		return (stack->nbr);
	else
		return (stack->index);
}

int	ft_peek_bigger(t_stack *stack, t_type type)
{
	t_stack	*temp_stack;
	int		bigger;
	int		next_value;

	temp_stack = stack;
	bigger = ft_peek(temp_stack, type);
	while (temp_stack->next)
	{
		next_value = ft_peek(temp_stack->next, type);
		if (bigger < next_value)
			bigger = next_value;
		temp_stack = temp_stack->next;
	}
	return (bigger);
}

int	ft_peek_smaller(t_stack *stack, t_type type)
{
	t_stack	*temp_stack;
	int		smaller;
	int		next_value;

	temp_stack = stack;
	smaller = ft_peek(temp_stack, type);
	while (temp_stack->next)
	{
		next_value = ft_peek(temp_stack->next, type);
		if (smaller > next_value)
			smaller = next_value;
		temp_stack = temp_stack->next;
	}
	return (smaller);
}
