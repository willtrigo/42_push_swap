/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:42:27 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/18 03:53:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"
#include "ft_default.h"
#include "internal/ft_parse.h"
#include "internal/handle/ft_error.h"

static void	ft_parse_single_argument(char **argv);
static void	ft_parse_list_arguments(char **list);

void	ft_parse_arguments(int argc, char **argv)
{
	if (argc == ZERO)
		ft_error();
	if (argc == SINGLE_ARGURMENT)
		ft_parse_single_argument(argv);
	else
		ft_parse_list_arguments(argv);
}

static void	ft_parse_single_argument(char **argv)
{
	int		nb_result;
	char	*endptr;
	char	**list_arguments;

	nb_result = ft_strtod(argv[DEFAULT], &endptr);
	if (*endptr == ' ')
	{
		list_arguments = ft_split(argv[DEFAULT], ' ');
		ft_parse_list_arguments(list_arguments);
	}
	else if (!*endptr)
		ft_putnbr_fd(nb_result, STDIN_FILENO);
	else
	{
		free(endptr);
		ft_error();
	}
}

static void	ft_parse_list_arguments(char **list)
{
	int		nb_result;
	char	*endptr;
	char	**list_temp;

	list_temp = list;
	while (*list)
	{
		nb_result = ft_strtod(*list, &endptr);
		if (!*endptr)
			ft_putnbr_fd(nb_result, STDIN_FILENO);
		else
			break ;
		free(*list++);
	}
	while (*list)
		free(*list++);
	free(list_temp);
	if (endptr)
		ft_error();
}
