/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:42:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/11 07:18:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/state/ft_peek.h"
#include <unistd.h>
#include "internal/handle/stack/ft_stack.h"

void	ft_print_stack(int target_stack)
{
	t_stack	*temp_stack;

	if (target_stack == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack)
	{
		ft_putnbr_fd(temp_stack->index, STDERR_FILENO);
		if (target_stack == STACK_A)
			ft_putendl_fd(" -> stack a", STDERR_FILENO);
		else
			ft_putendl_fd(" -> stack b", STDERR_FILENO);
		temp_stack = temp_stack->next;
	}
}

t_stacks	*ft_stack(void)
{
	static t_stacks	stack;

	return (&stack);
}

void	ft_stack_normalize(t_stack *stack, int stack_size)
{
	t_stack	*temp_stack;
	// t_stack	*temp_stack_bigger;
	int		temp_bigger_nbr;

	temp_bigger_nbr = ft_peek_bigger(stack);
	temp_stack = stack;
	while (temp_stack)
	{
		if (temp_stack->nbr == temp_bigger_nbr && temp_stack->index == INIT)
		{
			break ;
		}
		temp_stack = temp_stack->next;
	}
	temp_stack->index = --stack_size;
	// temp_stack = stack;
	// while (--stack_size)
	// {
	// 	temp_stack = stack;
	// 	while (temp_stack)
	// 	{
	// 		if (temp_stack->nbr < temp_bigger_nbr && temp_stack->index == INIT)
	// 		{
	// 			temp_stack_bigger = temp_stack;
	// 		}
	// 		temp_stack = temp_stack->next;
	// 	}
	// 	// if (temp_stack->index == INIT)
	// 	temp_stack_bigger->index = stack_size;
	// 	temp_bigger_nbr = temp_stack_bigger->nbr;
	// }
}
