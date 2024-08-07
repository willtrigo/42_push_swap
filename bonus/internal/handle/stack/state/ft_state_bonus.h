/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:10:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:23:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATE_BONUS_H
# define FT_STATE_BONUS_H

# include <stdbool.h>
# include "internal/handle/stack/ft_stack_bonus.h"

bool	ft_is_duplicate(t_stack *stack, int nbr);
bool	ft_is_sorted(t_stack *stack, int times);

#endif
