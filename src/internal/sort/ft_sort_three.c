/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/06 04:18:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/operation/ft_swap.h"
#include "internal/handle/stack/management/operation/ft_rotate.h"

void	ft_sort_three(int target_stack)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (target_stack == STACK_A)
	{
		if (stack->a->nbr == stack->info.max_nbr)
		{
			if (stack->a->next->nbr == stack->info.min_nbr)
				ft_swap(SA);
			else
			{
				// ft_swap(SA);
				// ft_rotate(RRA);
				ft_rotate(RA);
			}
		}
	}
}
