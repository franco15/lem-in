/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 04:24:27 by coco              #+#    #+#             */
/*   Updated: 2017/10/20 04:24:28 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*start_ants(t_list *rooms, int ants)
{
	int		i;
	t_ant	*ret;

	i = 0;
	if (!(ret = (t_ant*)ft_memalloc(sizeof(t_ant) * ants)))
	{
		printf("ded\n");
		exit(0);
	}
	while (i < ants)
	{
		ret[i].room = get_command(rooms, 1);
		ret[i].did_turn = 0;
		ret[i].which_ant = i + 1;
		i++;
	}
	return (ret);
}

static t_room	*start_room(char *line, int command)
{
	int		i;
	t_room	*ret;

	i = 0;
	if (!(ret = (t_room*)ft_memalloc(sizeof(t_room))))
	{
		printf("ded\n");
		exit(0);
	}
	while (line[i] != ' ')
		i++;
	ret->command = command;
	ret->name = ft_strsub(line, 0, i);
	// while (line[i] == ' ')
	// 	i++;
	// ret->x = ft_atoi(line + i);
	// while (line[i] != ' ')
	// 	i++;
	// while (line[i] == ' ')
	// 	i++;
	// ret->y = ft_atoi(line + i);
	ret->links = NULL;
	ret->wait = 0;
	ret->ant = 0;
	ft_memdel((void**)&line);
	return (ret);
}

int				read_file(t_lemin *l)
{
	int		i;
	int		command;
	char	*line;

	command = 0;
	while ((i = get_next_line(0, &line)) > 0)
	{
		ft_printf("%s\n", line);
		if (line[0] == '#')
		{
			if (line[1] == '#' && ft_strequ(line, "##start"))
				command = 1;
			else if (line[1] == '#' && ft_strequ(line, "##end"))
				command = 2;
			ft_memdel((void**)&line);
		}
		else if (is_room(line) && !l->rooms_kewl)
		{
			l->rooms = ft_lstpush(l->rooms, start_room(line, command));
			l->qr++;
			command = 0;
		}
		else if (is_link(l->rooms, line) && (l->rooms_kewl = 1))
		{
			l->links = ft_lstpush(l->links, ft_strsplit(line, '-'));
			ft_memdel((void**)&line);
		}
		else
			break ;
	}
	ft_memdel((void**)&line);
	return (i);
}
