/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/03 01:41:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/parse/ft_parse_arguments.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_destroy.h"

// # include "internal/handle/stack/operation/ft_swap.h"
# include "internal/handle/stack/operation/ft_rotate.h"
// # include "internal/handle/stack/operation/ft_push.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	ft_parse_arguments(--argc, ++argv, &stack);
	ft_print_stack(&stack, STACK_A);
	// ft_swap(&stack, SA);
	// ft_swap(&stack, SB);
	// ft_swap(&stack, SS);
	// ft_rotate(&stack, RA);
	// ft_rotate(&stack, RB);
	// ft_rotate(&stack, RR);
	ft_rotate(&stack, RRA);
	// ft_rotate(&stack, RRB);
	// ft_rotate(&stack, RRR);
	// ft_push(&stack, PA);
	// ft_push(&stack, PB);
	ft_print_stack(&stack, STACK_A);
	ft_stacks_destroy(&stack);
	exit(EXIT_SUCCESS);
}
