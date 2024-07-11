/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:22:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/11 05:45:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_pop.h"

static void	ft_push_stack(t_stack **stack, int nbr);

void	ft_push(t_operations operation)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (operation == PA && stack->info.a_size)
	{
		ft_push_stack(&stack->b, ft_pop(&stack->a));
		stack->info.b_size++;
		stack->info.a_size--;
	}
	if (operation == PB && stack->info.b_size)
	{
		ft_push_stack(&stack->a, ft_pop(&stack->b));
		stack->info.a_size++;
		stack->info.b_size--;
	}
	ft_output_operation(operation);
}

static void	ft_push_stack(t_stack **stack, int nbr)
{
	ft_stackadd_front(stack, ft_stacknew(nbr));
}
