/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 01:17:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_pop.h"
#include "internal/handle/stack/state/ft_peek.h"
#include "internal/sort/ft_sort.h"

static void	ft_rotate(t_operations operation);
static void	ft_rotate_stack(t_stack **stack);
static void	ft_reverse_rotate_stack(t_stack **stack);

void	ft_rotate_possibilities(t_operations operation, int times)
{
	t_stacks	*stack;

	stack = ft_stack();
	while (times--)
	{
		if (operation == RA && stack->info.b_size >= STACK_SIZE_TWO \
			&& stack->b->nbr < ft_stacklast(stack->b)->nbr)
			operation = RR;
		else if (operation == RB && stack->a->nbr > ft_stacklast(stack->a)->nbr)
			operation = RR;
		else if (operation == RRA && stack->info.b_size >= STACK_SIZE_TWO \
			&& ft_stacklast(stack->b)->nbr > stack->b->nbr)
			operation = RRR;
		else if (operation == RRB \
			&& ft_stacklast(stack->a)->nbr < stack->a->nbr)
			operation = RRR;
		ft_rotate(operation);
	}
}

static void	ft_rotate(t_operations operation)
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

	// last_node = find_last_node(*head);
	// last_node->prev->next = NULL;
	// last_node->next = *head;
	// last_node->prev = NULL;
	// *head = last_node;
	// last_node->next->prev = last_node;
}
