/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:47:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/26 05:26:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_ARGUMENTS_H
# define FT_PARSE_ARGUMENTS_H

# include "internal/stack/ft_stack.h"

enum e_arguments
{
	SINGLE_ARGURMENT = 1,
};

void	ft_parse_arguments(int argc, char **argv, t_stack *stack);

#endif
