/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:49:23 by coco              #+#    #+#             */
/*   Updated: 2017/06/29 02:49:23 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *elem;

	if (!(elem = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->size = 0;
	}
	else
	{
		elem->content = (void*)ft_memalloc(size);
		elem->content = ft_memcpy(elem->content, content, size);
		elem->size = size;
	}
	elem->next = NULL;
	return (elem);
}

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!*alst && !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
