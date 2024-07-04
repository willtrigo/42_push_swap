/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:22:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/03 04:34:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/ft_output.h"

void	ft_push(t_stacks *stack, t_operations operation)
{
	(void)stack;
	if (operation == PA)
	{
		ft_output_operation(PA);
	}
	else
	{
		ft_output_operation(PB);
	}
}
