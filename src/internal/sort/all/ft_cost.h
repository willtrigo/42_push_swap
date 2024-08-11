/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:23:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/11 02:30:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COST_H
# define FT_COST_H

# include <stdbool.h>
# include "internal/handle/stack/ft_stack.h"

typedef enum e_cost	t_cost;
enum e_cost
{
	TOP,
	BOT,
};

t_cost	ft_return_best_cost(int value, t_stack_targets target, bool is_between);
void	ft_push_number_to_b_top(t_stacks *stack, t_pivots *pivot);
void	ft_push_number_to_b_bot(t_stacks *stack, t_pivots *pivot);

#endif
