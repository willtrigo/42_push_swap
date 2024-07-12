/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:41:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/12 05:23:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATE_H
# define FT_STATE_H

# include <stdbool.h>
# include "internal/handle/stack/ft_stack.h"

enum e_sorted
{
	REVERSE = 1,
};

bool	ft_is_duplicate(t_stack *stack, int nbr);
bool	ft_is_sorted(t_stack *stack, int type);

#endif
