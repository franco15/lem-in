/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:00:23 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/09 19:00:24 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*get_next_room(t_lemin *l, char *path)
{
	(void)l;
	printf("%s\n", path);
	return (0);
}

static void	lemin_start(t_lemin *l, char **link)
{
	int		i;
	char	*next;
	char	**path;

	i = 0;
	path = (char**)ft_memalloc(sizeof(char*) * l->rooms);
	if (!ft_strncmp(link[0], l->start, ft_strlen(link[0])))
		path[i++] = ft_strdup(link[1]);
	else
		path[i++] = ft_strdup(link[0]);
	while ((next = get_next_room(l, path[i - 1])) && i < l->rooms)
	{
		path[i++] = ft_strdup(next);
		ft_memdel((void**)&next);
	}
	ft_arrdel((void**)path);
}

void		lem_in(t_lemin *l)
{
	int		i;
	int		start;

	i = 0;
	start = get_room(l, l->start);
	while (i < l->links)
	{
		if (!ft_strncmp(l->link[i][0], l->start, ft_strlen(l->link[i][0])) ||
			!ft_strncmp(l->link[i][1], l->start, ft_strlen(l->link[i][1])))
			lemin_start(l, l->link[i]);
		i++;
	}
	printf("\n");
	i = 0;
	for (i = 0; i < l->rooms; i++)
	{
		for (int j = 0; j < l->rooms; j++)
			printf("%d ", l->lonk[i][j]);
		printf("\n");
	}
}

/*
while (i < # of links to start)
{

}
*/
