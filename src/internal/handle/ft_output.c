/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:29:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 04:33:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/ft_output.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_destroy.h"

void	ft_output_error(void)
{
	ft_stacks_destroy();
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_output_operation(t_operations operation)
{
	static const char	*operations_output[] = {
	[SA] = "sa",
	[SB] = "sb",
	[SS] = "ss",
	[RA] = "ra",
	[RB] = "rb",
	[RR] = "rr",
	[RRA] = "rra",
	[RRB] = "rrb",
	[RRR] = "rrr",
	[PA] = "pa",
	[PB] = "pb",
	};

	ft_putendl_fd((char *)operations_output[operation], STDERR_FILENO);
}
