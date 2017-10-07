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
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	j = get_file_len(av);
	l->flen = j;
	fd = open(av, O_RDONLY);
	l->file = (char**)ft_memalloc(sizeof(char*) * j);
	while (i < j)
	{
		get_next_line(fd, &line);
		l->file[i++] = ft_strdup(line);
	}
	close(fd);
	// get_ants(l);
	// for (i = 0; i < j; i++)
	// 	printf("%s\n", l->file[i]);
}

int			main(int ac, char **av)
{
	t_lemin	l;

	if (ac < 2)
		return (0);
		structure_thing(&l, av[1]);
	return (1);
}