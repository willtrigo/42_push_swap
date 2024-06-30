/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:58:29 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/30 03:52:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILD_STACK_H
# define FT_BUILD_STACK_H

# include "internal/stack/ft_stack.h"

t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *node_new);
t_stack	*ft_stacknew(int nbr);
_Bool	ft_is_duplicate(t_stack *stack, int nbr);

#endif
