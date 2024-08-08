/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:48:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/08 14:22:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack_bonus.h"

void	ft_output_error(void)
{
	ft_stacks_destroy();
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
