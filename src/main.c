/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:50:15 by coco              #+#    #+#             */
/*   Updated: 2017/10/20 03:50:16 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lemin_error(char *str)
{
	t_lemin	*l;

	l = retrieve_lemin(0);
	printf("%s\n", str);
	ded(l);
	exit(1);
}

t_lemin		*retrieve_lemin(t_lemin *l)
{
	static t_lemin	*ll = NULL;

	if (l)
		ll = l;
	return (ll);
}

static void	start_lemin(t_lemin *l)
{
	l->qr = 0;
	l->moves = 0;
	l->rooms = NULL;
	l->links = NULL;
	if (!(l->qa = get_qa()))
		lemin_error("ded: failed to get quantity of ants");
	if (read_file(l) == -1)
		lemin_error("ded: failed to read_file");
	if (!l->rooms || !l->links)
		lemin_error("ded: failed to get rooms and\\or links");
	l->ants = start_ants(l->rooms, l->qa);
}

int		main(int ac, char **av)
{
	t_lemin	*l;

	(void)ac;
	(void)av;
	if (!(l = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
		lemin_error("ded: @ first malloc");
	retrieve_lemin(l);
	start_lemin(l);
	lemin(l);
	ded(l);
}
