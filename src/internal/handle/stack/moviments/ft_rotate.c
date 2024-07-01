/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 04:17:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack.h"

void	ft_rotate(t_stacks stack, int mov)
{
	(void)stack;
	if (mov == RA)
	{
		ft_putendl_fd("ra", STDIN_FILENO);
	}
	else if (mov == RB)
	{
		ft_putendl_fd("rb", STDIN_FILENO);
	}
	else if (mov == RR)
	{
		ft_putendl_fd("rr", STDIN_FILENO);
	}
	else if (mov == RRA)
	{
		ft_putendl_fd("rra", STDIN_FILENO);
	}
	else if (mov == RRB)
	{
		ft_putendl_fd("rrb", STDIN_FILENO);
	}
	else
	{
		ft_putendl_fd("rrr", STDIN_FILENO);
	}
}
