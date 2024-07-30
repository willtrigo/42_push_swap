/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:41:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 02:56:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/handle/stack/state/ft_state.h"

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

bool	ft_is_sorted(t_stack *stack, t_type type, int times)
{
	t_stack	*temp_stack;
	int		is_sorted;

	temp_stack = stack;
	while (--times && temp_stack->next)
	{
		if (type == STACK_INDEX || type == STACK_INDEX_REVERSE)
			is_sorted = temp_stack->index;
		else
			is_sorted = temp_stack->nbr;
		if (type == STACK_INDEX && !((is_sorted + STACK_NODE) \
			== temp_stack->next->index))
			return (false);
		else if (type == STACK_INDEX_REVERSE && !((is_sorted - STACK_NODE) \
			== temp_stack->next->index))
			return (false);
		else if (type == STACK_NBR && !((is_sorted + STACK_NODE) \
			== temp_stack->next->nbr))
			return (false);
		temp_stack = temp_stack->next;
	}
	return (true);
}
