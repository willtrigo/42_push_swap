/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:20:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 04:37:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/management/ft_stack_build.h"
#include "internal/handle/stack/management/operation/ft_pop.h"

static void	ft_swap_stack(t_stack **stack);

void	ft_swap(t_operations operation)
{
	t_stacks *stack;

	stack = ft_stack();
	if (operation == SA || operation == SS)
		ft_swap_stack(&stack->a);
	if (operation == SB || operation == SS)
		ft_swap_stack(&stack->b);
	ft_output_operation(operation);
}

static void	ft_swap_stack(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_stack = (*stack);
	if (!temp_stack || !temp_stack->next)
		return ;
	temp_stack = ft_stacklast(*stack);
	temp_nbr = ft_pop(&(*stack));
	ft_stackadd_back(&temp_stack, ft_stacknew(temp_nbr));
}
