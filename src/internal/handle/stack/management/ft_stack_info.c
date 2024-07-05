/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:41:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 13:29:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/management/ft_stack_info.h"
#include "internal/handle/stack/ft_stack.h"

bool	ft_is_duplicate(t_stack *stack, int nbr)
{
	if (!stack)
		return (false);
	else
	{
		while (stack)
		{
			if (stack->nbr == nbr)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

int	ft_peek(t_stack *stack)
{
	return (stack->nbr);
}

int	ft_get_bigger(t_stack *stack)
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
