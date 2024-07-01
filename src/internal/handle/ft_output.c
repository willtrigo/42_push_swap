/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:29:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 04:48:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/management/ft_stack_destroy.h"
#include "internal/handle/ft_output.h"

void	ft_output_error(t_stacks *stack)
{
	ft_stacks_destroy(stack);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_output_moviment(int mov)
{
	if (mov == SA)
		ft_putendl_fd("sa", STDERR_FILENO);
	if (mov == SB)
		ft_putendl_fd("sb", STDERR_FILENO);
	if (mov == SS)
		ft_putendl_fd("ss", STDERR_FILENO);
	if (mov == PA)
		ft_putendl_fd("pa", STDERR_FILENO);
	if (mov == PB)
		ft_putendl_fd("pb", STDERR_FILENO);
	if (mov == RA)
		ft_putendl_fd("ra", STDERR_FILENO);
	if (mov == RB)
		ft_putendl_fd("rb", STDERR_FILENO);
	if (mov == RR)
		ft_putendl_fd("rr", STDERR_FILENO);
	if (mov == RRA)
		ft_putendl_fd("rra", STDERR_FILENO);
	if (mov == RRB)
		ft_putendl_fd("rrb", STDERR_FILENO);
	if (mov == RRR)
		ft_putendl_fd("rrr", STDERR_FILENO);
}
