/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:22:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 12:29:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_build.h"
#include "internal/handle/stack/management/operation/ft_push.h"
#include "internal/handle/stack/management/operation/ft_pop.h"

static void	ft_push_stack(t_stack **stack, int nbr);

void	ft_push(t_operations operation)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (operation == PA && stack->info.a_len)
	{
		ft_push_stack(&stack->b, ft_pop(&stack->a));
		stack->info.b_len++;
		stack->info.a_len--;
	}
	if (operation == PB && stack->info.b_len)
	{
		ft_push_stack(&stack->a, ft_pop(&stack->b));
		stack->info.a_len++;
		stack->info.b_len--;
	}
	ft_output_operation(operation);
}

static void	ft_push_stack(t_stack **stack, int nbr)
{
	ft_stackadd_front(stack, ft_stacknew(nbr));
}
