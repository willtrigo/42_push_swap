/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:47:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/05 04:14:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_ARGUMENTS_H
# define FT_PARSE_ARGUMENTS_H

enum e_arguments
{
	SINGLE_ARGURMENT = 1,
};

void	ft_parse_arguments(int argc, char **argv);

#endif
