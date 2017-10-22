/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 05:45:18 by coco              #+#    #+#             */
/*   Updated: 2017/10/20 05:45:19 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_ant(t_lemin *l, t_room *next)
{
	printf("ant: %s\n", l->ants->room->name);
	l->ants->prev = l->ants->room;
	l->ants->room = next;
}

t_room			*get_command(t_list *rooms, int command)
{
	t_room	*ret;

	while (rooms)
	{
		ret = (t_room*)rooms->content;
		if (ret->command == command)
			return (ret);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room	*get_room(t_list *rooms, char *room)
{
	t_room	*tmp;

	while (rooms)
	{
		tmp = (t_room*)rooms->content;
		if (ft_strequ(room, tmp->name))
			return (tmp);
		rooms = rooms->next;
	}
	return (NULL);
}

int				is_link(t_list *rooms, char *line)
{
	char	**doors;

	doors = NULL;
	if (ft_strchr(line, '-'))
	{
		doors = ft_strsplit(line, '-');
		if (get_room(rooms, doors[0]) && get_room(rooms, doors[1]))
		{
			ft_arrdel((void**)doors, 2);
			return (1);
		}
	}
	ft_arrdel((void**)doors, 2);
	return (0);
}

int				is_room(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i++] != ' ')
		return (0);
	if (line[i] == '-')
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i++] != ' ')
		return (0);
	if (line[i] == '-')
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}
