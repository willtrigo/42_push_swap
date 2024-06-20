/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:49:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/20 04:36:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"
#include "ft_stdlib.h"

void	ft_parse_nbr(char *str_nbr, int nbr)
{
	if ((nbr * 1.0) == ft_atof(str_nbr))
		ft_putnbr_fd(nbr, STDIN_FILENO);
}
