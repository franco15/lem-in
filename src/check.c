/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 03:44:47 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/22 03:44:49 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_links(t_lemin *l, void *room, int command)
{
	int		new_distance;
	int		curr_distance;
	t_room	*curr_room;
	t_list	*tmp;

	curr_room = (t_room*)room;
	if (curr_room->command == command)
		return (0);
	if (curr_room->wait)
		return (-1);
	curr_room->wait = 1;
	curr_distance = 2147483647;
	tmp = curr_room->links;
	while (tmp)
	{
		if ((new_distance = check_links(l, tmp->content, command)) <
			curr_distance && new_distance != -1)
			curr_distance = new_distance + 1;
		tmp = tmp->next;
	}
	curr_room->wait = 0;
	if (curr_distance == 2147483647)
		return (-1);
	return (curr_distance);
}

static int	check_rooms(t_list *rooms)
{
	int		start;
	int		end;
	t_room	*tmp;
	t_list	*trooms;

	start = 0;
	end = 0;
	if (!rooms)
		return (0);
	trooms = rooms;
	while (trooms)
	{
		tmp = (t_room*)trooms->content;
		if (tmp->name[0] == '#' || ft_strchr(tmp->name, '-') ||
			ft_strchr(tmp->name, 'L'))
			return (0);
		if (tmp->command == 1)
			start++;
		if (tmp->command == 2)
			end++;
		trooms = trooms->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

static int	no_end(t_list *rooms, t_list *links)
{
	int		ded;
	char	**tmp;
	t_list	*tl;
	t_room	*end;

	ded = 0;
	tl = links;
	while (tl)
	{
		tmp = (char**)tl->content;
		end = get_command(rooms, 2);
		if (ft_strequ(tmp[0], end->name) ||
			ft_strequ(tmp[1], end->name))
			ded++;
		tl = tl->next;
	}
	if (!ded)
		return (0);
	return (1);
}

void		check_intel(t_lemin *l)
{
	t_room	*start;

	start = get_command(l->rooms, 1);
	if (start && l->links)
		if (check_links(l, start, 1) < 0)
			lemin_error("ded: probably no path to reach end");
	if (!check_rooms(l->rooms))
		lemin_error("ded: check that rooms are kewl (specially start/end)");
	if (!no_end(l->rooms, l->links))
		lemin_error("ded: probably no link to end");
}
