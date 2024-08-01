/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_nbrs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:44:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/01 04:46:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETURN_NBRS_H
# define FT_RETURN_NBRS_H

# include "internal/handle/stack/ft_stack.h"

void	ft_return_sorted_all(t_stacks *stack, t_pivots *pivot);
void	ft_return_nbr_between(t_stacks *stack, int value, t_pivots *pivot);
void	ft_return_nbr(t_stacks *stack, int value, t_pivots *pivot);

#endif
