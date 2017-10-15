/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 17:49:20 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/14 17:49:21 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_link(t_lemin *l, int n)
{
	int	i;
	int	j;

	i = get_room(l, l->link[n][0]);
	j = get_room(l, l->link[n][1]);
	if (l->lonk[i][j])
		printf("%d\n", l->lonk[i][j]);
	return (l->lonk[i][j]);
}

int			get_link(t_lemin *l, int i)
{
	while (i < l->links)
	{
		if (!ft_strncmp(l->link[i][0], l->room[l->whereami],
			ft_strlen(l->link[i][0])) || !ft_strncmp(l->link[i][1],
			l->room[l->whereami], ft_strlen(l->link[i][0])))
		{
			if (check_link(l, i))
				return (i);
		}
		i++;
	}
	return (-1);
}
