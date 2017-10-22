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

static void	check_ants(t_lemin *l)
{
	(void)l;
}

static void	reset_ants(t_ant *ants, int qa)
{
	(void)ants;
	(void)qa;
}

static int	conti_nue(t_ant *ants, int qa)
{
	int	i;

	i = 0;
	while (i < qa)
	{
		if (ants[i].room->command == 2)
			return (0);
		i++;
	}
	return (1);
}

void	solve_lemin(t_lemin *l)
{
	while (conti_nue(l->ants, l->qa))
	{
		reset_ants(l->ants, l->qa);
		check_ants(l);
	}
}
