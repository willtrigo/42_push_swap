/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:41:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/06 02:42:44 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_INFO_H
# define FT_STACK_INFO_H

# include <stdbool.h>
# include "internal/handle/stack/ft_stack.h"

bool	ft_is_duplicate(t_stack *stack, int nbr);
int		ft_peek(t_stack *stack);
int		ft_peek_bigger(t_stack *stack);
int		ft_peek_smaller(t_stack *stack);
bool	ft_is_sorted(t_stack *stack);

#endif
