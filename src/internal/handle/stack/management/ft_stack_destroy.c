/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:55:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 04:34:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/management/ft_stack_destroy.h"
#include "internal/handle/stack/ft_stack.h"

static void	ft_stack_destroy(t_stack *stack);

void	ft_stacks_destroy(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (stack->a)
		ft_stack_destroy(stack->a);
	if (stack->b)
		ft_stack_destroy(stack->b);
}

static void	ft_stack_destroy(t_stack *stack)
{
	t_stack	*temp_stack;

	while (stack)
	{
		temp_stack = stack;
		stack = stack->next;
		free(temp_stack);
	}
}
