/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:52:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/07 07:23:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

void	ft_sort_three(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (stack->a->nbr == stack->info.max_nbr)
	{
		if (ft_is_sorted(stack->a->next))
			ft_rotate(RA);
		else
		{
			ft_rotate(RA);
			ft_swap(SA);
		}
	}
	else
		ft_swap(SA);
}
