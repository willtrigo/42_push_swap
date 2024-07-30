/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:20:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/30 01:48:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/sort/ft_sort.h"

static void	ft_swap(t_operations operation);
static void	ft_swap_stack(t_stack **stack);

void	ft_swap_possibilities(t_operations operation)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (operation == SA)
	{
		if (stack->info.b_size >= STACK_SIZE_TWO \
			&& stack->b->nbr < stack->b->next->nbr)
			operation = SS;
	}
	else if (operation == SB)
	{
		if (stack->a->nbr > stack->a->next->nbr)
			operation = SS;
	}
	ft_swap(operation);
}

static void	ft_swap(t_operations operation)
{
	t_stacks	*stack;

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
	temp_nbr = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp_nbr;
}
