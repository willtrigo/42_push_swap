/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:58:35 by dande-je          #+#    #+#             */
/*   Updated: 2024/06/26 07:15:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_default.h"
#include "internal/stack/ft_stack.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*node_new;

	node_new = ft_calloc(CHAR_BYTE, sizeof(t_stack));
	if (!node_new)
		return (NULL);
	node_new->nbr = nbr;
	node_new->next = NULL;
	node_new->prev = NULL;
	return (node_new);
}
