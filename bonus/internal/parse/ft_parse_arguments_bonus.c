/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:04:56 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/11 00:22:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_default.h"
#include "ft_non_standard/ft_non_standard.h"
#include "internal/parse/ft_parse_arguments_bonus.h"
#include "internal/handle/ft_output_bonus.h"
#include "internal/handle/stack/ft_stack_bonus.h"
#include "internal/handle/stack/state/ft_state_bonus.h"

static int	ft_parse_single_argument(char **argv);
static int	ft_parse_list_arguments(char **list, int nbr, int valid_parse, \
				char *nbr_endptr);
static void	ft_parse_arguments_with_space(char *arg);
static int	ft_parse_nbr(char *str_nbr, int nbr, int add_stack);

void	ft_parse_arguments(int argc, char **argv)
{
	int	valid_parse;

	if (argc == DEFAULT)
		exit(EXIT_SUCCESS);
	else if (argc == SINGLE_ARGURMENT)
		valid_parse = ft_parse_single_argument(argv);
	else
		valid_parse = ft_parse_list_arguments(argv, DEFAULT, true, NULL);
	if (valid_parse == FAIL)
		ft_output_error();
}

static int	ft_parse_single_argument(char **argv)
{
	char	*nbr_endptr;
	char	*argv_trim;

	argv_trim = ft_strtrim(*argv, " ");
	ft_strtoi(argv_trim, &nbr_endptr);
	if (!*nbr_endptr)
	{
		free(argv_trim);
		exit(EXIT_SUCCESS);
	}
	else if (*nbr_endptr == ' ')
		ft_parse_arguments_with_space(*argv);
	else
		return (FAIL);
	free(argv_trim);
	return (true);
}

static int	ft_parse_list_arguments(char **list, int nbr, int valid_parse, \
				char *nbr_endptr)
{
	char	*list_trim;

	while (*list)
	{
		list_trim = ft_strtrim(*list, " ");
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
		free(list_trim);
	}
	if (valid_parse == FAIL)
		free(list_trim);
	return (valid_parse);
}

static void	ft_parse_arguments_with_space(char *arg)
{
	int		valid_parse;
	char	**list_arguments;
	char	**list_arguments_temp;
	char	*arg_trim;

	arg_trim = ft_strtrim(arg, " ");
	list_arguments = ft_split(arg_trim, ' ');
	list_arguments_temp = list_arguments;
	valid_parse = ft_parse_list_arguments(list_arguments, DEFAULT, true, NULL);
	while (*list_arguments)
		free(*list_arguments++);
	free(list_arguments_temp);
	free(arg_trim);
	if (valid_parse == FAIL)
		ft_output_error();
}

static int	ft_parse_nbr(char *str_nbr, int nbr, int add_stack)
{
	t_stacks	*stack;

	stack = ft_stack();
	if ((nbr * 1.0) == ft_atof(str_nbr) && add_stack)
	{
		stack->info.a_size++;
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
