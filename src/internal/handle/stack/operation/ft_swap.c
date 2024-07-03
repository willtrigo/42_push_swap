/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:20:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/03 04:35:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/ft_output.h"

static void	ft_swap_stack(t_stack **stack);

void	ft_swap(t_stacks *stack, t_operations operation)
{
	if (operation == SA || operation == SS)
		ft_swap_stack(&stack->a);
	if (operation == SB || operation == SS)
		ft_swap_stack(&stack->b);
	ft_output_operation(operation);
}

static void	ft_swap_stack(t_stack **stack)
{
	t_stack	*temp_stack;

	temp_stack = (*stack);
	if (!temp_stack || !temp_stack->next)
		return ;
	(*stack) = temp_stack->next;
	temp_stack->prev = NULL;
	temp_stack->next = (*stack)->next;
	(*stack)->next = temp_stack;
	temp_stack->prev = (*stack);
	if (temp_stack->next)
		temp_stack->next->prev = temp_stack;
}
