/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:41:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/07 06:38:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/state/ft_peek.h"

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


bool	ft_is_sorted(t_stack *stack)
{
	t_stack	*temp_stack;
	int		is_sorted;

	temp_stack = stack;
	while (temp_stack->next)
	{
		is_sorted = ft_peek(temp_stack);
		if (is_sorted > ft_peek(temp_stack->next))
			return (false);
		temp_stack = temp_stack->next;
	}
	return (true);
}
