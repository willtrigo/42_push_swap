/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/05 16:53:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_peek.h"

t_stacks	*ft_stack(void)
{
	static t_stacks	stack;

	return (&stack);
}

void	ft_set_pivots(t_stack *stack, t_pivots *pivot)
{
	int	temp_bigger;

	ft_stack_normalize(STACK_INDEX);
	pivot->first = ft_peek(stack, STACK_INDEX);
	pivot->smaller = ft_peek_smaller(stack, STACK_INDEX);
	pivot->bigger = ft_peek_bigger(stack, STACK_INDEX);
	temp_bigger = ft_peek_bigger(stack, STACK_NBR) + STACK_NODE;
	if (pivot->mid == INIT)
	{
		if (temp_bigger == STACK_SIZE_FIVE)
			pivot->mid = temp_bigger / STACK_SIZE_TWO;
		else if (temp_bigger >= STACK_SIZE_FOURHUNDRED)
			pivot->mid = ((pivot->bigger + STACK_NODE) - STACK_SIZE_FOUR) \
				/ STACK_SIZE_EIGHT;
		else if (temp_bigger >= STACK_SIZE_HUNDRED)
			pivot->mid = ((pivot->bigger + STACK_NODE) - STACK_SIZE_FOUR) \
				/ STACK_SIZE_FOUR;
		else
			pivot->mid = temp_bigger / STACK_SIZE_TWO;
	}
	if (stack->next)
		pivot->next = stack->next->index;
	pivot->last = ft_stacklast(stack)->index;
}
