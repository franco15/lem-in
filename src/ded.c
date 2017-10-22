/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ded.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:13:22 by coco              #+#    #+#             */
/*   Updated: 2017/10/21 18:13:23 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	link_ded(void *link)
{
	char	**tmp;

	tmp = (char**)link;
	ft_arrdel((void**)tmp, 2);
}

static void	room_ded(void *room)
{
	t_room	*tmp;

	tmp = (t_room*)room;
	ft_memdel((void**)&tmp->name);
	ft_lst_rec_free(tmp->links);
	ft_memdel((void**)&room);
}

void		ded(t_lemin *l)
{
	ft_lstforeach(l->rooms, room_ded);
	ft_lst_rec_free(l->rooms);
	ft_lstforeach(l->links, link_ded);
	ft_lst_rec_free(l->links);
	ft_memdel((void**)&l->ants);
	ft_memdel((void**)&l);
}
