/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:11:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/18 10:39:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TARGETS_H
# define FT_TARGETS_H

# include "internal/handle/stack/ft_stack.h"

void	ft_target_bigger(t_pivots pivot);
void	ft_target_penult(t_pivots pivot);
void	ft_target_small_mid(t_pivots pivot);

#endif
