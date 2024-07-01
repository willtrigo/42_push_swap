/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:20:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/01 04:17:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack.h"

void	ft_swap(t_stacks stack, int mov)
{
	(void)stack;
	if (mov == SA)
	{
		ft_putendl_fd("sa", STDIN_FILENO);
	}
	else if (mov == SB)
	{
		ft_putendl_fd("sb", STDIN_FILENO);
	}
	else
	{
		ft_putendl_fd("ss", STDIN_FILENO);
	}
}
