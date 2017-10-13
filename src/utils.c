/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:00:11 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/06 19:00:12 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_lemin(t_lemin *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < l->rooms)
		ft_memdel((void**)&l->room[i++]);
	free(l->room);
	i = -1;
	while (++i < l->links)
	{
		j = -1;
		while (++j < 2)
			ft_memdel((void**)&l->link[i][j]);
		free(l->link[i]);
	}
	free(l->link);
	i = 0;
	while (i < l->rooms)
	{
		ft_memdel((void**)&l->lonk[i++]);
		// ft_memdel((void**)&l->path[i++]);
	}
	free(l->lonk);
	// free(l->path);
	ft_memdel((void**)&l->end);
	ft_memdel((void**)&l->start);
}
