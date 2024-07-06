/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/06 02:49:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/parse/ft_parse_arguments.h"
#include "internal/sort/ft_sort.h"
#include "internal/handle/stack/management/ft_stack_destroy.h"


int	main(int argc, char **argv)
{
	ft_parse_arguments(--argc, ++argv);
	ft_sort();
	ft_stacks_destroy();
	exit(EXIT_SUCCESS);
}
