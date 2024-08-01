/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/01 02:00:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/state/ft_peek.h"

t_stacks	*ft_stack(void)
{
	static t_stacks	stack;

	return (&stack);
}

void	ft_set_pivots(t_stack *stack, t_pivots *pivot)
{
	ft_stack_normalize(STACK_INDEX);
	pivot->first = ft_peek(stack, STACK_INDEX);
	pivot->smaller = ft_peek_smaller(stack, STACK_INDEX);
	pivot->bigger = ft_peek_bigger(stack, STACK_INDEX);
	if (pivot->bigger + STACK_NODE == STACK_SIZE_FIVE)
		pivot->mid = pivot->bigger / STACK_SIZE_TWO;
	else if (pivot->bigger >= STACK_SIZE_HUNDRED)
		pivot->mid = (pivot->bigger + STACK_NODE) / STACK_SIZE_TEN;
	else
		pivot->mid = pivot->bigger / STACK_SIZE_FOUR;
	if (stack->next)
		pivot->next = stack->next->index;
	pivot->last = ft_stacklast(stack)->index;
}

#include "ft_non_standard/ft_non_standard.h"
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
