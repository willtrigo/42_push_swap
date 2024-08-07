/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:10:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:29:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/state/ft_state_bonus.h"

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

bool	ft_is_sorted(t_stack *stack, int times)
{
	t_stack	*temp_stack;
	int		is_sorted;

	temp_stack = stack;
	while (--times && temp_stack->next)
	{
		is_sorted = temp_stack->nbr;
		if (!(is_sorted + STACK_NODE == temp_stack->next->nbr))
			return (false);
		temp_stack = temp_stack->next;
	}
	return (true);
}
