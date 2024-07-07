/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/07 07:40:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"
#include "internal/handle/stack/state/ft_state.h"

void	ft_sort_five(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (stack->a->nbr == stack->info.max_nbr)
	{
		if (ft_is_sorted(stack->a->next))
			ft_rotate(RA);
		else if (ft_is_sorted(stack->a->next->next))
		{
			ft_push(PA);
			ft_rotate(RA);
			ft_push(PB);
			ft_rotate(RA);
		}
		else
		{
			ft_push(PA);
			ft_sort_five();
		}
	}
	else
		ft_swap(SA);
}
