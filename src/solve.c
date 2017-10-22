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
	int		curr_distance;
	int		new_distance;
	t_list	*links;
	t_room	*tmp;
	t_room	*next;

	curr_distance = l->qr;
	links = l->ants[i].room->links;
	while (links)
	{
		tmp = (t_room*)links->content;
		if ((tmp->command == 2 || !tmp->ant) && tmp != l->ants->prev)
		{
			new_distance = check_links(l, tmp);
			if (new_distance < curr_distance)
			{
				curr_distance = new_distance;
				next = tmp;
			}
		}
		links = links->next;
	}
	if (curr_distance < l->qr)
		print_ant(l, next, i);
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
		if ((!room->ant && (room->command != 1) &&
			room != ant->prev) || room->command == 2)
		{
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
	int	ret;

	i = 0;
	ret = 1;
	while (i < qa)
	{
		if (ants[i].room->command != 2)
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}

static void	check_ants(t_lemin *l)
{
	int	i;
	int	quit;

	quit = 1;
	while (quit && !conti_nue(l->ants, l->qa))
	{
		i = 0;
		while (i < l->qa)
		{
			// printf("hola\n");
			if (can_move(l->ants, i))
			{
				quit = 0;
				confirm_ant(l, i);
				// break ;
			}
			i++;
		}
		ft_printf("\n");
	}
}

void	solve_lemin(t_lemin *l)
{
	int	i;

	while (!conti_nue(l->ants, l->qa))
	{
		i = 0;
		while (i < l->qa)
			l->ants[i++].did_move = 0;
		check_ants(l);
	}
}
