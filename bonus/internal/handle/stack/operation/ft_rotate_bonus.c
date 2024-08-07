/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:05:14 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 05:30:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/ft_output_bonus.h"
#include "internal/handle/stack/ft_stack_bonus.h"
#include "internal/handle/stack/operation/ft_rotate_bonus.h"

static void	ft_rotate_stack(t_stack **stack);
static void	ft_reverse_rotate_stack(t_stack **stack);

void	ft_rotate(t_operations operation)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (operation == RA || operation == RR)
		ft_rotate_stack(&stack->a);
	if (operation == RB || operation == RR)
		ft_rotate_stack(&stack->b);
	if (operation == RRA || operation == RRR)
		ft_reverse_rotate_stack(&stack->a);
	if (operation == RRB || operation == RRR)
		ft_reverse_rotate_stack(&stack->b);
	ft_output_operation(operation);
}

static void	ft_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;

	temp_stack = ft_stacklast(*stack);
	if (!temp_stack || !temp_stack->prev)
		return ;
	temp_stack->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp_stack->next->prev = temp_stack;
	temp_stack->next->next = NULL;
}

static void	ft_reverse_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;

	temp_stack = ft_stacklast(*stack);
	if (!temp_stack || !temp_stack->prev)
		return ;
	temp_stack->prev->next = NULL;
	temp_stack->next = (*stack);
	temp_stack->prev = NULL;
	*stack = temp_stack;
	temp_stack->next->prev = temp_stack;
}
