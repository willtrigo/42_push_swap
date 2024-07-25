/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targets.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:19:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/25 04:03:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TARGETS_H
# define FT_TARGETS_H

# include "internal/handle/stack/ft_stack.h"

void	ft_push_to_stack_b(t_stacks *stack, t_pivots *pivot);
void	ft_stay_in_the_same_stack(t_pivots *pivot);

#endif
