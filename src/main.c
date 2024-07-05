/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 13:26:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/parse/ft_parse_arguments.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_destroy.h"

# include "internal/handle/stack/management/operation/ft_swap.h"
# include "internal/handle/stack/management/operation/ft_rotate.h"
# include "internal/handle/stack/management/operation/ft_push.h"
# include "internal/sort/ft_sort.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(--argc, ++argv);
	ft_print_stack(STACK_A);
	ft_print_stack(STACK_B);
	ft_swap(SA);
	ft_swap(SB);
	ft_swap(SS);
	ft_rotate(RA);
	ft_rotate(RB);
	ft_rotate(RR);
	ft_rotate(RRA);
	ft_rotate(RRB);
	ft_rotate(RRR);
	ft_push(PA);
	ft_push(PA);
	ft_push(PA);
	ft_push(PA);
	ft_push(PA);
	ft_push(PB);
	ft_rotate(RRA);
	ft_print_stack(STACK_A);
	ft_print_stack(STACK_B);
	ft_sort();
	ft_stacks_destroy();
	exit(EXIT_SUCCESS);
}
