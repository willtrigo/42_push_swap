/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:22:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/04 08:18:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_build.h"
#include "internal/handle/stack/management/operation/ft_push.h"
#include "internal/handle/stack/management/operation/ft_pop.h"

static void	ft_push_stack(t_stack **stack, int nbr);

void	ft_push(t_stacks *stack, t_operations operation)
{
	if (operation == PA && stack->a_len)
	{
		ft_push_stack(&stack->b, ft_pop(&stack->a));
		stack->b_len++;
		stack->a_len--;
	}
	if (operation == PB && stack->b_len)
	{
		ft_push_stack(&stack->a, ft_pop(&stack->b));
		stack->a_len++;
		stack->b_len--;
	}
	ft_output_operation(operation);
}

static void	ft_push_stack(t_stack **stack, int nbr)
{
	ft_stackadd_front(stack, ft_stacknew(nbr));
}
