/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 06:13:08 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/22 06:13:10 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	confirm_ant(t_lemin *l, int i)
{
	// printf("confirm_ant\n");
	(void)l;
	(void)i;
}

static int	can_move(t_ant *ant, int i)
{
	int	yes;
	int it_can;
	t_list	*links;
	t_room	*room;

	if (ant[i].room->command == 2)
		return (0);
	yes = 1;
	it_can = 0;
	if (ant[i].did_move)
		yes = 0;
	links = ant[i].room->links;
	while (yes && links)
	{
		room = (t_room*)links->content;
		if ((!room->ant && (room->command && room->command != 1) &&
			room != ant->prev) || room->command == 2)
		{
			printf("hola %d\n", room->command);
			it_can = 1;
			break ;
		}
		links = links->next;
	}
	if (yes && it_can)
		return (1);
	return (0);
}

static int	conti_nue(t_ant *ants, int qa)
{
	int	i;

	i = 0;
	while (i < qa)
	{
		if (ants[i].room->command == 2)
		{
			printf("ded continue\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	check_ants(t_lemin *l)
{
	int	i;

	while (conti_nue(l->ants, l->qa))
	{
		i = 0;
		while (i < l->qa)
		{
			// printf("dedadsd\n");
			if (can_move(l->ants, i))
			{
				// printf("%d\n", i);
				confirm_ant(l, i);
				break ;
				// printf("smn\n");
			}
			i++;
		}
	}
	// printf("ded\n");
}

void	solve_lemin(t_lemin *l)
{
	int	i;

	while (conti_nue(l->ants, l->qa))
	{
		i = 0;
		while (i < l->qa)
			l->ants[i++].did_move = 0;
		check_ants(l);
	}
}
