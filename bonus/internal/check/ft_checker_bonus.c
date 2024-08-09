/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:39:20 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/09 15:30:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_non_standard/ft_non_standard.h"
#include "ft_non_standard/ft_get_next_line.h"
#include "internal/handle/ft_output_bonus.h"
#include "internal/handle/stack/ft_stack_bonus.h"
#include "internal/handle/stack/operation/ft_rotate_bonus.h"
#include "internal/handle/stack/operation/ft_swap_bonus.h"
#include "internal/handle/stack/operation/ft_push_bonus.h"
#include "internal/handle/stack/state/ft_state_bonus.h"

static void	ft_command(char *command);

void	ft_checker(void)
{
	char		*command;
	t_stacks	*stack;

	stack = ft_stack();
	ft_stack_normalize();
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		ft_command(command);
		free(command);
		command = get_next_line(STDIN_FILENO);
	}
	if (!stack->info.b_size && ft_is_sorted(stack->a, stack->info.a_size))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

static void	ft_command(char *command)
{
	if (!ft_strncmp(command, "pa\n", ft_strlen("pa\n")))
		ft_push(PA, ONE_TIME);
	else if (!ft_strncmp(command, "pb\n", ft_strlen("pb\n")))
		ft_push(PB, ONE_TIME);
	else if (!ft_strncmp(command, "ra\n", ft_strlen("ra\n")))
		ft_rotate(RA);
	else if (!ft_strncmp(command, "rb\n", ft_strlen("rb\n")))
		ft_rotate(RB);
	else if (!ft_strncmp(command, "rr\n", ft_strlen("rr\n")))
		ft_rotate(RR);
	else if (!ft_strncmp(command, "rra\n", ft_strlen("rra\n")))
		ft_rotate(RRA);
	else if (!ft_strncmp(command, "rrb\n", ft_strlen("rrb\n")))
		ft_rotate(RRB);
	else if (!ft_strncmp(command, "rrr\n", ft_strlen("rrr\n")))
		ft_rotate(RRR);
	else if (!ft_strncmp(command, "sa\n", ft_strlen("sa\n")))
		ft_swap(SA);
	else if (!ft_strncmp(command, "sb\n", ft_strlen("sb\n")))
		ft_swap(SB);
	else if (!ft_strncmp(command, "ss\n", ft_strlen("ss\n")))
		ft_swap(SS);
	else
		ft_output_error();
}
