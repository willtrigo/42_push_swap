/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:06:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/07/18 08:13:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include <stdbool.h>

enum e_sort_size
{
	SORT_THREE = 3,
	SORT_FOUR = 4,
	SORT_FIVE = 5,
};

enum e_stack_size
{
	STACK_SIZE_TWO = 2,
	STACK_SIZE_FOUR = 4,
};

enum e_stack_node
{
	STACK_NODE = 1,
};

void	ft_sort(void);
bool	ft_is_ready_to_sorted_reverse(void);

#endif
