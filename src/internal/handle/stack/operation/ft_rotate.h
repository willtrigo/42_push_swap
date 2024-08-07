/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:23:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/05 16:44:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROTATE_H
# define FT_ROTATE_H

# include <stdbool.h>
# include "internal/handle/stack/ft_stack.h"

void	ft_rotate_possibilities(t_operations operation, int times, \
			bool active_bonus);

#endif
