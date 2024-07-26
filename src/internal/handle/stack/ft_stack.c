/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/26 05:08:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"
#include <unistd.h>

void	ft_print_stack(int target_stack)
{
	t_stack	*temp_stack;

	if (target_stack == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack)
	{
		ft_putnbr_fd(temp_stack->nbr, STDERR_FILENO);
		ft_putstr_fd(" | ", STDERR_FILENO);
		ft_putnbr_fd(temp_stack->index, STDERR_FILENO);
		if (target_stack == STACK_A)
			ft_putendl_fd(" -> stack a", STDERR_FILENO);
		else
			ft_putendl_fd(" -> stack b", STDERR_FILENO);
		temp_stack = temp_stack->next;
	}
}

t_stacks	*ft_stack(void)
{
	static t_stacks	stack;

	return (&stack);
}

void	ft_set_pivots(t_stack *stack, t_pivots *pivot)
{
	pivot->first = ft_peek(stack, STACK_INDEX);
	pivot->smaller = ft_peek_smaller(stack, STACK_INDEX);
	pivot->bigger = ft_peek_bigger(stack, STACK_INDEX);
	pivot->mid = pivot->bigger / 2;
	if (stack->next)
		pivot->next = stack->next->index;
	pivot->last = ft_stacklast(stack)->index;
}
