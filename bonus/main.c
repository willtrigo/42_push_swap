/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:35:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/06 12:41:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/parse/ft_parse_arguments_bonus.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(--argc, ++argv);
	exit(EXIT_SUCCESS);
}
