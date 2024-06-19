/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:42:27 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/19 04:45:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_default.h"
#include "internal/ft_parse.h"
#include "internal/handle/ft_error.h"

static int	ft_parse_single_argument(char **argv);
static int	ft_parse_list_arguments(char **list);
static int	ft_parse_arguments_with_space(char *arg);

void	ft_parse_arguments(int argc, char **argv)
{
	int	valid_parse;

	if (argc == ZERO)
		ft_error();
	if (argc == SINGLE_ARGURMENT)
		valid_parse = ft_parse_single_argument(argv);
	else
		valid_parse = ft_parse_list_arguments(argv);
	if (valid_parse == FAIL)
		ft_error();
}

static int	ft_parse_single_argument(char **argv)
{
	int		nb_result;
	char	*endptr;

	nb_result = ft_strtoi(argv[DEFAULT], &endptr);
	if (!*endptr)
		ft_putnbr_fd(nb_result, STDIN_FILENO);
	else if (*endptr == ' ')
		return (ft_parse_arguments_with_space(argv[DEFAULT]));
	else
		return (FAIL);
	return (true);
}

static int	ft_parse_list_arguments(char **list)
{
	int		nb_result;
	int		valid_parse;
	char	*endptr;

	valid_parse = true;
	while (*list && valid_parse)
	{
		nb_result = ft_strtoi(*list, &endptr);
		if (!*endptr)
			ft_putnbr_fd(nb_result, STDIN_FILENO);
		else if (*endptr == ' ')
		{
			if (ft_parse_arguments_with_space(*list) == FAIL)
				valid_parse = FAIL;
		}
		else
			valid_parse = FAIL;
		list++;
	}
	if (valid_parse == FAIL)
		return (FAIL);
	return (true);
}

static int	ft_parse_arguments_with_space(char *arg)
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
		return (FAIL);
	return (true);
}
