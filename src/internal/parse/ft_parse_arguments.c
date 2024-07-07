/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:42:27 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 12:30:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_stdlib.h"
#include "ft_default.h"
#include "internal/handle/ft_output.h"
#include "internal/parse/ft_parse_arguments.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/management/ft_stack_build.h"
#include "internal/handle/stack/management/ft_stack_info.h"

static int	ft_parse_single_argument(char **argv);
static int	ft_parse_list_arguments(char **list);
static void	ft_parse_arguments_with_space(char *arg);
static int	ft_parse_nbr(char *str_nbr, int nbr, int add_stack);

void	ft_parse_arguments(int argc, char **argv)
{
	int	valid_parse;

	if (argc == SINGLE_ARGURMENT)
		valid_parse = ft_parse_single_argument(argv);
	else
		valid_parse = ft_parse_list_arguments(argv);
	if (valid_parse == FAIL)
		ft_output_error();
}

static int	ft_parse_single_argument(char **argv)
{
	int		nbr;
	char	*nbr_endptr;

	nbr = ft_strtoi(*argv, &nbr_endptr);
	if (!*nbr_endptr)
		return (ft_parse_nbr(*argv, nbr, false));
	else if (*nbr_endptr == ' ')
		ft_parse_arguments_with_space(*argv);
	else
		return (FAIL);
	return (true);
}

static int	ft_parse_list_arguments(char **list)
{
	int		nbr;
	int		valid_parse;
	char	*nbr_endptr;

	valid_parse = true;
	while (*list)
	{
		nbr = ft_strtoi(*list, &nbr_endptr);
		if (!*nbr_endptr)
			valid_parse = ft_parse_nbr(*list, nbr, true);
		else if (*nbr_endptr == ' ')
			ft_parse_arguments_with_space(*list);
		else
			valid_parse = FAIL;
		if (valid_parse == FAIL)
			break ;
		list++;
	}
	if (valid_parse == FAIL)
		return (FAIL);
	return (true);
}

static void	ft_parse_arguments_with_space(char *arg)
{
	int		valid_parse;
	char	**list_arguments;
	char	**list_arguments_temp;

	list_arguments = ft_split(arg, ' ');
	list_arguments_temp = list_arguments;
	valid_parse = ft_parse_list_arguments(list_arguments);
	while (*list_arguments)
		free(*list_arguments++);
	free(list_arguments_temp);
	if (valid_parse == FAIL)
		ft_output_error();
}

static int	ft_parse_nbr(char *str_nbr, int nbr, int add_stack)
{
	t_stacks	*stack;

	stack = ft_stack();
	if ((nbr * 1.0) == ft_atof(str_nbr) && add_stack)
	{
		stack->info.a_len++;
		if (!stack->a)
			ft_stackadd_back(&stack->a, ft_stacknew(nbr));
		else
		{
			if (ft_is_duplicate(stack->a, nbr))
				ft_stackadd_back(&stack->a, ft_stacknew(nbr));
			else
				return (FAIL);
		}
	}
	else if ((nbr * 1.0) != ft_atof(str_nbr))
		return (FAIL);
	return (true);
}