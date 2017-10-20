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

void		check_link(t_lemin *l, int n)
{
	(void)l;
	(void)n;
	// int	i;
	// int	j;
	//
	// i = get_room(l, l->link[n][0]);
	// j = get_room(l, l->link[n][1]);
	// if (ft_strncmp(l->room[i], l->room[l->whereami], ))
}

int			get_link(t_lemin *l, int n)
{
	int	i;
	int	j;

	while (n < l->links)
	{
		if (!ft_strncmp(l->link[n][0], l->room[l->whereami],
			ft_strlen(l->link[n][0])) || !ft_strncmp(l->link[n][1],
			l->room[l->whereami], ft_strlen(l->link[n][0])))
		{
			i = get_room(l, l->link[n][0]);
			j = get_room(l, l->link[n][1]);
			if (l->lonk[i][j])
			{
				printf("%d\n", l->lonk[i][j]);
				return (n);
			}
		}
		n++;
	}
	return (-1);
}
