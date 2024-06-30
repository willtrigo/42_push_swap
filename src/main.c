/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/30 04:56:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/handle/ft_output_error.h"
#include "internal/parse/ft_parse_arguments.h"
#include "internal/stack/ft_stack.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	ft_parse_arguments(--argc, ++argv, &stack);
	ft_print_stack(&stack);
	ft_stacks_destroy(&stack);
	exit(EXIT_SUCCESS);
}
