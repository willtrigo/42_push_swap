/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 14:28:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_build.h"
#include "internal/handle/ft_output.h"

// void	ft_rotate(t_stacks *stack, int operation)
// {
// 	(void)stack;
// 	if (operation == RA)
// 	{
// 		ft_output_moviment(RA);
// 	}
// 	else if (operation == RB)
// 	{
// 		ft_output_moviment(RB);
// 	}
// 	else if (operation == RR)
// 	{
// 		ft_output_moviment(RR);
// 	}
// 	else if (operation == RRA)
// 	{
// 		ft_output_moviment(RRA);
// 	}
// 	else if (operation == RRB)
// 	{
// 		ft_output_moviment(RRB);
// 	}
// 	else
// 	{
// 		ft_output_moviment(RRR);
// 	}
// }

static void	ft_rotate_stack(t_stack **stack);

void	ft_rotate(t_stacks *stack, int operation)
{
	if (operation == RA || operation == RR)
		ft_rotate_stack(&stack->a);
	if (operation == RB || operation == RR)
		ft_rotate_stack(&stack->b);
	ft_output_moviment(operation);
}

static void	ft_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;

	temp_stack = ft_stacklast(*stack);
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
