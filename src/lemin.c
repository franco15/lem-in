/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:11:39 by coco              #+#    #+#             */
/*   Updated: 2017/10/21 17:11:40 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_room_links(t_lemin *l)
{
	char	**link;
	t_list	*links;
	t_list	*rooms;
	t_room	*room;

	rooms = l->rooms;
	while (rooms)
	{
		room = (t_room*)rooms->content;
		links = l->links;
		while (links)
		{
			link = (char**)links->content;
			if (ft_strequ(link[0], room->name))
				room->links = ft_lstpush(room->links, get_room(l->rooms, link[1]));
			if (ft_strequ(link[1], room->name))
				room->links = ft_lstpush(room->links, get_room(l->rooms, link[0]));
			links = links->next;
		}
		rooms = rooms->next;
	}
}

void		lemin(t_lemin *l)
{
	get_room_links(l);
	check_intel(l);
}
