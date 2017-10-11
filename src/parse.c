/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:28:29 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/09 10:28:30 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_room(t_lemin *l, char *s)
{
	int	i;

	i = 0;
	while (i < l->rooms)
	{
		if (!ft_strncmp(s, l->room[i], ft_strlen(s)))
			return (i);
		i++;
	}
	return (-1);
}

void		lonks(t_lemin *l)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	k = -1;
	while (++k < l->links)
	{
		s = ft_strsplit(l->link[k], '-');
		i = get_room(l, s[0]);
		j = get_room(l, s[1]);
		if (i < 0 || j < 0)
			ft_error("room doesn't exist");
		l->lonk[i][j] = 1;
		l->lonk[j][i] = 1;
	}
}

static void	get_links(t_lemin *l, int fd, char *line)
{
	int	i;

	i = 0;
	ft_printf("%s\n", line);
	ft_strncmp("#", line, 1) ? (l->link[i++] = ft_strdup(line)) : 0;
	ft_memdel((void**)&line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (ft_strncmp("#", line, 1))
			l->link[i++] = ft_strdup(line);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	l->links = i;
	ft_printf("\n");
}

void		get_rooms(t_lemin *l, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0 && !ft_strchr(line, '-'))
	{
		ft_printf("%s\n", line);
		if (!ft_strncmp("##start", line, 7))
		{
			ft_memdel((void**)&line);
			get_next_line(fd, &line);
			ft_printf("%s\n", (l->start = ft_strdup(line)));
		}
		else if (!ft_strncmp("##end", line, 5))
		{
			ft_memdel((void**)&line);
			get_next_line(fd, &line);
			ft_printf("%s\n", (l->end = ft_strdup(line)));
		}
		ft_strncmp("#", line, 1) ? (l->room[i++] = ft_strdup(line)) : 0;
		ft_memdel((void**)&line);
	}
	l->rooms = i;
	get_links(l, fd, line);
}
