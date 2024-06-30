/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:29:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/30 05:01:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/ft_output_error.h"
#include "internal/stack/ft_stack.h"

static void	ft_stack_destroy(t_stack *stack);

void	ft_output_error(t_stacks *stack)
{
	ft_stacks_destroy(stack);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_stacks_destroy(t_stacks *stack)
{
	if (stack->a)
		ft_stack_destroy(stack->a);
	if (stack->b)
		ft_stack_destroy(stack->b);
}

static void	ft_stack_destroy(t_stack *stack)
{
	t_stack	*temp_stack;

	while (stack)
	{
		temp_stack = stack;
		stack = stack->next;
		free(temp_stack);
	}
}
