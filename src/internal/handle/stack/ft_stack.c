/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 05:03:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack.h"

void	ft_print_stack(t_stacks *stack, int target_stack)
{
	t_stack	*temp_stack;

	if (target_stack == STACK_A)
		temp_stack = stack->a;
	else
		temp_stack = stack->b;
	while (temp_stack)
	{
		ft_putnbr_fd(temp_stack->nbr, STDIN_FILENO);
		if (target_stack == STACK_A)
			ft_putendl_fd(" -> stack a", STDIN_FILENO);
		else
			ft_putendl_fd(" -> stack b", STDIN_FILENO);
		temp_stack = temp_stack->next;
	}
}
