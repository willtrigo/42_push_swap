/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:04:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/08 14:25:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/operation/ft_push_bonus.h"
#include "internal/handle/stack/operation/ft_pop_bonus.h"

static void	ft_push_stack(t_stack **stack, int nbr);

void	ft_push(t_operations operation, int times)
{
	t_stacks	*stack;

	stack = ft_stack();
	while (times--)
	{
		if (operation == PB && stack->info.a_size)
		{
			ft_push_stack(&stack->b, ft_pop(&stack->a));
			stack->info.b_size++;
			stack->info.a_size--;
		}
		if (operation == PA && stack->info.b_size)
		{
			ft_push_stack(&stack->a, ft_pop(&stack->b));
			stack->info.a_size++;
			stack->info.b_size--;
		}
	}
}

static void	ft_push_stack(t_stack **stack, int nbr)
{
	ft_stackadd_front(stack, ft_stacknew(nbr));
}
