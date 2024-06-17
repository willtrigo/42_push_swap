/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:42:27 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/17 03:45:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_parse.h"
#include "internal/handle/ft_error.h"

void	ft_parse_arguments(int argc, char **argv)
{
	(void)argv;
	if (argc == BLANK)
		ft_error();
}
