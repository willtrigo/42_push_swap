/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:22:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 05:18:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/ft_output.h"

void	ft_push(t_stacks *stack, int operation)
{
	(void)stack;
	if (operation == PA)
	{
		ft_output_moviment(PA);
	}
	else
	{
		ft_output_moviment(PB);
	}
}
