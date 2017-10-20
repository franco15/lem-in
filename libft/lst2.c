/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 05:21:02 by coco              #+#    #+#             */
/*   Updated: 2017/10/20 05:21:02 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

t_list		*ft_lstpush(t_list *first, void *content)
{
	t_list	*tmp;

	if (!content)
		return (NULL);
	if (!first)
	{
		first = (t_list *)ft_memalloc(sizeof(t_list));
		first->content = content;
		first->next = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_list *)ft_memalloc(sizeof(t_list));
		tmp->next->content = content;
		tmp->next->next = NULL;
	}
	return (first);
}