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

static void	start_lemin(t_lemin *l)
{
	l->qr = 0;
	l->moves = 0;
	l->rooms = NULL;
	l->links = NULL;
	if (!(l->qa = get_qa()))
	{
		printf("ded at qa\n");
		return ;
	}
	if (read_file(l) == -1)
	{
		printf("ded at read_file\n");
		return ;
	}
	if (!l->rooms || !l->links)
	{
		printf("ded after read_file\n");
		return ;
	}
	l->ants = start_ants(l->rooms, l->qa);
}

int		main(int ac, char **av)
{
	t_lemin	*l;

	(void)ac;
	(void)av;
	if (!(l = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
		return (printf("ded\n"));
	start_lemin(l);
	lemin(l);
	ded(l);
}
