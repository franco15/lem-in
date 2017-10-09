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

void	get_rooms(t_lemin *l, int fd)
{
	int		i;
	char	*line;

	i = 0;
	l->room = (char**)ft_memalloc(sizeof(char*) * 1000);
	while (get_next_line(fd, &line) > 0 && !ft_strchr(line, '-'))
	{
		if (!ft_strncmp("##start", line, 7))
			l->start = ft_strndup(line, 7);
		else if (!ft_strncmp("##end", line, 5))
			l->end = ft_strndup(line, 5);
		l->room[i++] = ft_strdup(line);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	l->rooms = i;
	printf("smn\n");
}
