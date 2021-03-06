/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_before_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 05:00:19 by nle-bret          #+#    #+#             */
/*   Updated: 2016/12/13 05:00:20 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_before_node(t_list *list, t_link *node, t_link *new_node)
{
	t_link	*n_prev;

	if (node == new_node || list == NULL || node == NULL || new_node == NULL)
		return ;
	if (node->prev != NULL)
	{
		n_prev = node->prev;
		n_prev->next = new_node;
		new_node->prev = n_prev;
		new_node->next = node;
		node->prev = new_node;
	}
	else
	{
		new_node->next = node;
		node->prev = new_node;
		list->head = new_node;
	}
	list->size++;
}
