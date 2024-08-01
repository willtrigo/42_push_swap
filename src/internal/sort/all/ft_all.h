/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:32:29 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/01 04:48:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALL_H
# define FT_ALL_H

# include "internal/handle/stack/ft_stack.h"

void	ft_sort_all(void);
void	ft_one_operation_to_finish(t_stacks *stack);
int		ft_get_cost(int value);

#endif
