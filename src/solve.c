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

static void	confirm_ant(t_lemin *l)
{
	int		curr_distance;
	int		new_distance;
	t_list	*links;
	t_room	*tmp;
	t_room	*next;

	curr_distance = l->qr;
	links = l->ants->room->links;
	while (links)
	{
		tmp = (t_room*)links->content;
		if ((tmp->command == 2 || !tmp->ant) && tmp != l->ants->prev)
		{
			new_distance = check_links(l, tmp, 2);
			if (new_distance != -1 && new_distance < curr_distance)
			{
				curr_distance = new_distance;
				next = tmp;
			}
		}
		links = links->next;
	}
	if (curr_distance < l->qr)
		print_ant(l, l->ants, next);
}

static int	can_move(t_ant *ant)
{
	int		yes;
	int		it_can;
	t_list	*links;
	t_room	*room;

	if (ant->room->command == 2)
		return (0);
	yes = 1;
	it_can = 0;
	if (ant->did_move)
		yes = 0;
	links = ant->room->links;
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
	return (yes && it_can);
}

static int	conti_nue(t_ant *ants, int qa)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (i < qa && ants != 0)
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

	quit = 0;
	while (!quit && !conti_nue(l->ants, l->qa))
	{
		i = 0;
		quit = 1;
		while (i < l->qa)
		{
			if (can_move(l->ants + i))
			{
				quit = 0;
				l->ants += i;
				confirm_ant(l);
				l->ants -= i;
			}
			i++;
		}
		ft_printf("\n");
	}
}

void		solve_lemin(t_lemin *l)
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
