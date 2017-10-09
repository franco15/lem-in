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

static void	structure_thing(t_lemin *l, char *av)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	get_next_line(fd, &line);
	l->ants = ft_atoi(line);
	ft_printf("%d\n", l->ants);
	ft_memdel((void**)&line);
	get_rooms(l, fd);
}

int			main(int ac, char **av)
{
	t_lemin	l;

	if (ac < 2)
		return (0);
	structure_thing(&l, av[1]);
	exit_lemin(&l);
	return (1);
}
