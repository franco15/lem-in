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
// check rooms: checa que el nombre de cada room no incluya '-' '#' o 'L' y
// checa que nomas exista una room con flag start y una con flag end

int			check_links(t_lemin *l, void *start)
{
	int		prev_distance;
	int		curr_distance;
	t_room	*curr_room;
	t_list	*tmp;

	curr_room = (t_room*)start;
	if (curr_room->command == 2)
		return (1);
	if (curr_room->wait)
		return (0);
	curr_room->wait = 1;
	curr_distance = l->qr;
	tmp = curr_room->links;
	while (tmp)
	{
		if ((prev_distance = check_links(l, tmp->content)) < curr_distance &&
			prev_distance != -1)
			curr_distance = prev_distance + 1;
		tmp = tmp->next;
	}
	curr_room->wait = 0;
	if (curr_distance == l->qr)
		return (0);
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
		if (tmp->name[0] == '#' || ft_strchr(tmp->name, '-'))
			return (0);
		if (tmp->command == 1)
			start++;
		if (tmp->command == 2)
			end++;
		trooms = trooms->next;
	}
	if (start != 1 && end != 1)
		return (0);
	return (1);
}

void	check_intel(t_lemin *l)
{
	t_room	*start;

	start = get_command(l->rooms, 1);
	if (start && l->links)
	{
		if (!check_links(l, start))
		{
			ded(l);
			exit(1);
		}
	}
	// if (check_paths(get_command(l->rooms, 2), l->links))
	// {
	// 	ded(l);
	// 	exit(1);
	// }
	if (!check_rooms(l->rooms))
	{
		ded(l);
		exit(1);
	}
}
