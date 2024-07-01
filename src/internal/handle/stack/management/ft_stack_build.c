/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:58:35 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 04:30:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_stdlib.h"
#include "ft_default.h"
#include "internal/handle/stack/management/ft_stack_build.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*node_new;

	node_new = ft_calloc(CHAR_BYTE, sizeof(t_stack));
	if (!node_new)
		return (NULL);
	node_new->nbr = nbr;
	node_new->next = NULL;
	node_new->prev = NULL;
	return (node_new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *node_new)
{
	if (!*stack)
		*stack = node_new;
	else
	{
		ft_stacklast(*stack)->next = node_new;
		node_new->prev = ft_stacklast(*stack);
	}
}

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
