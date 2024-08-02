/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:23:58 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/02 03:51:30 by dande-je         ###   ########.fr       */
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

t_cost	ft_return_best_cost(int value, t_stack_targets target, \
			bool is_between, int stack_size);

#endif
