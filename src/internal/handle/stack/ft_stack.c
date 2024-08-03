/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/03 03:46:24 by dande-je         ###   ########.fr       */
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
	ft_stack_normalize(STACK_INDEX);
	pivot->first = ft_peek(stack, STACK_INDEX);
	pivot->smaller = ft_peek_smaller(stack, STACK_INDEX);
	pivot->bigger = ft_peek_bigger(stack, STACK_INDEX);
	if (pivot->mid == DEFAULT)
	{
		if (pivot->bigger + STACK_NODE == STACK_SIZE_FIVE)
			pivot->mid = pivot->bigger / STACK_SIZE_TWO;
		else if (pivot->bigger >= 400)
			// pivot->mid = (pivot->bigger + STACK_NODE) / STACK_SIZE_TEN;
			// pivot->mid = STACK_SIZE_FORTY;
			pivot->mid = 75;
		else if (pivot->bigger + STACK_NODE >= STACK_SIZE_HUNDRED)
			// pivot->mid = (pivot->bigger + STACK_NODE) / STACK_SIZE_TEN;
			pivot->mid = 25;
		else
			pivot->mid = pivot->bigger / STACK_SIZE_FOUR;
	}
	if (stack->next)
		pivot->next = stack->next->index;
	pivot->last = ft_stacklast(stack)->index;
}
