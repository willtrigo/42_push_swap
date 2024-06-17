/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/17 00:57:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/ft_parse.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(argc, argv);
	exit(EXIT_SUCCESS);
}
