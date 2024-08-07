/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 03:27:56 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/07 03:30:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PEEK_BONUS_H
# define FT_PEEK_BONUS_H

# include "internal/handle/stack/ft_stack_bonus.h"

int	ft_peek(t_stack *stack, t_type type);
int	ft_peek_bigger(t_stack *stack, t_type type);
int	ft_peek_smaller(t_stack *stack, t_type type);

#endif
