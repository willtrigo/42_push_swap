/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets_reverse.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:12:36 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/16 09:13:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TARGETS_REVERSE_H
# define FT_TARGETS_REVERSE_H

# include "internal/handle/stack/ft_stack.h"

void	ft_target_smaller_reverse(t_pivots pivot);
void	ft_target_next_smaller_reverse(t_pivots pivot);
void	ft_target_penult_reverse(t_pivots pivot);
void	ft_target_next_reverse(t_pivots pivot);
void	ft_target_bigger_reverse(t_pivots pivot);

#endif
