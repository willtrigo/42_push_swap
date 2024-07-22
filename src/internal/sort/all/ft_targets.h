/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/21 21:20:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TARGETS_H
# define FT_TARGETS_H

# include "internal/handle/stack/ft_stack.h"

void	ft_target_is_smaller(t_pivots *pivot);
void	ft_target_is_first_equal_next(t_stacks *stack, t_pivots *pivot);
void	ft_target_is_last_equal_first(t_stacks *stack, t_pivots *pivot);
void	ft_target_default(t_stacks *stack, t_pivots *pivot);

#endif
