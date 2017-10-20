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

static int	start_link_end(t_lemin *l)
{
	int		i;
	int		j;

	i = get_room(l, l->start);
	j = get_room(l, l->end);
	if (l->lonk[i][j] || l->lonk[j][i])
	{
		l->path[l->p++] = ft_strdup(l->room[j]);
		printf("smn, start-end link\n");
		return (1);
	}
	return (0);
}

void		lem_in(t_lemin *l, int x, int y)
{
	int		i;

	(void)x;
	(void)y;
	i = 0;
	if (start_link_end(l) && l->p == 0)
		return ;
	while ((i = get_link(l, i)) != -1 && i < l->links)
	{
		if (is_end(l, i))
			return ;
		check_link(l, i);
		break ;
	}
	i = 0;
	printf("\n");
	for (i = 0; i < l->rooms; i++)
	{
		for (int j = 0; j < l->rooms; j++)
			printf("%d ", l->lonk[i][j]);
		printf("\n");
	}
}
