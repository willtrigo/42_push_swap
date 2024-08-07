/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:05:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/08 14:25:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/operation/ft_swap_bonus.h"

static void	ft_swap_stack(t_stack **stack);

void	ft_swap(t_operations operation)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (operation == SA || operation == SS)
		ft_swap_stack(&stack->a);
	if (operation == SB || operation == SS)
		ft_swap_stack(&stack->b);
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
