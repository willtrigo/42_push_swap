/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 05:18:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/ft_output.h"

void	ft_rotate(t_stacks *stack, int operation)
{
	(void)stack;
	if (operation == RA)
	{
		ft_output_moviment(RA);
	}
	else if (operation == RB)
	{
		ft_output_moviment(RB);
	}
	else if (operation == RR)
	{
		ft_output_moviment(RR);
	}
	else if (operation == RRA)
	{
		ft_output_moviment(RRA);
	}
	else if (operation == RRB)
	{
		ft_output_moviment(RRB);
	}
	else
	{
		ft_output_moviment(RRR);
	}
}
