/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:06:24 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/06 04:01:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_sort_three.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_info.h"

#include <stdio.h>
void	ft_sort(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	if (!ft_is_sorted(stack->a))
	{
		stack->info.max_nbr = ft_peek_bigger(stack->a);
		stack->info.min_nbr = ft_peek_smaller(stack->a);
		ft_print_stack(STACK_A);
		ft_print_stack(STACK_B);
		if (stack->info.a_len <= SORT_THREE)
			ft_sort_three(STACK_A);
		ft_print_stack(STACK_A);
		ft_print_stack(STACK_B);
		if (ft_is_sorted(stack->a))
			printf("sorted.\n");
	}
}