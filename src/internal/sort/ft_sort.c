/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:06:24 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/27 18:01:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"
#include "internal/sort/ft_sort.h"
#include "internal/sort/ft_three.h"
#include "internal/sort/four/ft_four.h"
#include "internal/sort/all/ft_all.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/ft_normalize.h"
#include "internal/handle/stack/state/ft_state.h"
#include "internal/handle/stack/operation/ft_push.h"
#include "internal/handle/stack/operation/ft_swap.h"
#include "internal/handle/stack/operation/ft_rotate.h"

#include "ft_non_standard/ft_non_standard.h"
void	ft_sort(void)
{
	t_stacks	*stack;

	stack = ft_stack();
	ft_stack_normalize(STACK_DEFAULT);
	if (!ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
	{
		ft_putendl_fd("Init stack A\n", STDERR_FILENO);
		ft_print_stack(STACK_A);
		ft_print_stack(STACK_B);
		ft_putendl_fd("\nOperations:", STDERR_FILENO);
		if (stack->info.a_size <= SORT_THREE)
			ft_sort_three(DEFAULT);
		else if (stack->info.a_size == SORT_FOUR)
			ft_sort_four(DEFAULT);
		else if (stack->info.a_size > SORT_FOUR)
			ft_sort_all();
	}
	ft_putendl_fd("\nEnd stack A", STDERR_FILENO);
	ft_print_stack(STACK_A);
	ft_print_stack(STACK_B);
	ft_stack_normalize(STACK_DEFAULT);
	if (ft_is_sorted(stack->a, STACK_INDEX, stack->info.a_size))
		ft_putendl_fd("\nsorted.", STDERR_FILENO);
	else
		ft_putendl_fd("\nnot sorted.", STDERR_FILENO);
}

bool	ft_is_ready_to_sorted_reverse(void)
{
	t_stacks	*stack;
	int			push_size;

	stack = ft_stack();
	ft_stack_normalize(STACK_INDEX);
	push_size = DEFAULT;
	if (ft_is_sorted(stack->a, STACK_INDEX_REVERSE, stack->info.a_size))
	{
		while (ft_stack()->info.a_size - STACK_SIZE_FOUR)
		{
			ft_rotate_possibilities(RRA, ONE_TIME);
			ft_push(PB, ONE_TIME);
			push_size++;
		}
		ft_swap_possibilities(SA);
		ft_rotate_possibilities(RA, TWO_TIMES);
		ft_swap_possibilities(SA);
		ft_push(PA, push_size);
		return (true);
	}
	return (false);
}
