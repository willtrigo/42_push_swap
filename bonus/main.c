/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:35:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:43:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/parse/ft_parse_arguments_bonus.h"
#include "internal/check/ft_checker_bonus.h"
#include "internal/handle/stack/ft_stack_bonus.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(--argc, ++argv);
	ft_checker();
	ft_stacks_destroy();
	exit(EXIT_SUCCESS);
}
