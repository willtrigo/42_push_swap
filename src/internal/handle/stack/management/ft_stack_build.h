/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_build.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:58:29 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/04 06:43:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_BUILD_H
# define FT_STACK_BUILD_H

# include "internal/handle/stack/ft_stack.h"

t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *node_new);
void	ft_stackadd_front(t_stack **stack, t_stack *node_new);
t_stack	*ft_stacknew(int nbr);

#endif
