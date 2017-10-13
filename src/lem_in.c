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

// static void	get_next_room(t_lemin *l, char *path, int j)
// {
// 	(void)l;
// 	(void)path;
// 	(void)j;
// }
//
// static void	lemin_start(t_lemin *l, char **link)
// {
// 	(void)l;
// 	(void)link;
// }

void		lem_in(t_lemin *l)
{
	int		i;

	i = 0;
	printf("\n");
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
