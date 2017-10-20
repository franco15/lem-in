/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:39:25 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/06 17:39:26 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	read_thing(t_lemin *l)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	ft_printf("%d\n", (l->ants = ft_atoi(line)));
	ft_memdel((void**)&line);
	l->link = (char***)ft_memalloc(sizeof(char**) * 1000);
	l->room = (char**)ft_memalloc(sizeof(char*) * 1000);
	get_rooms(l, 0);
	l->lonk = (int**)ft_memalloc(sizeof(int*) * l->rooms);
	i = 0;
	while (i < l->rooms)
		l->lonk[i++] = (int*)ft_memalloc(sizeof(int) * l->rooms);
	l->path = (char**)ft_memalloc(sizeof(char*) * l->rooms);
	l->p = 0;
	lonks(l);
}

int			main(void)
{
	t_lemin	l;

	read_thing(&l);
	lem_in(&l, 0, 0);
	free_lemin(&l);
	return (0);
}
