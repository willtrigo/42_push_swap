/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/12 10:40:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_pop.h"

static void	ft_rotate_stack(t_stack **stack);
static void	ft_reverse_rotate_stack(t_stack **stack);

void	ft_rotate(t_operations operation, int times)
{
	t_stacks	*stack;

	stack = ft_stack();
	while (times--)
	{
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
}

static void	ft_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_stack = ft_stacklast(*stack);
	if (!temp_stack || !temp_stack->prev)
		return ;
	temp_nbr = ft_pop(stack);
	ft_stackadd_back(&temp_stack, ft_stacknew(temp_nbr));
}

static void	ft_reverse_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;
	int		temp_nbr;

	temp_stack = ft_stacklast(*stack);
	if (!temp_stack || !temp_stack->prev)
		return ;
	temp_nbr = ft_pop(&temp_stack);
	ft_stackadd_front(stack, ft_stacknew(temp_nbr));
}
