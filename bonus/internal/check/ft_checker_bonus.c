/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:39:20 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:53:42 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/handle/stack/ft_stack_bonus.h"

void	ft_checker(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	ft_stack_normalize();
	(void)stack;
	return ;
}
