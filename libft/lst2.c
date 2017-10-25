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

t_list		*ft_lstpush(t_list *list, void *content)
{
	t_list	*tmp;

	if (!content)
		return (NULL);
	if (!list)
	{
		list = (t_list *)ft_memalloc(sizeof(t_list));
		list->content = content;
		list->next = NULL;
	}
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_list *)ft_memalloc(sizeof(t_list));
		tmp->next->content = content;
		tmp->next->next = NULL;
	}
	return (list);
}

void		ft_lstforeach(t_list *list, void (*f)())
{
	t_list		*tmp;

	tmp = list;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

void		ft_lst_rec_free(t_list *list)
{
	if (list)
	{
		ft_lst_rec_free(list->next);
		free(list);
	}
}
