/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:29:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/20 02:02:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/output/ft_error.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
