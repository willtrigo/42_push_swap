/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:48:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/27 19:22:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PEEK_H
# define FT_PEEK_H

# include "internal/handle/stack/ft_stack.h"

int	ft_peek(t_stack *stack, t_type type);
int	ft_peek_bigger(t_stack *stack, t_type type);
int	ft_peek_smaller(t_stack *stack, t_type type);

#endif
