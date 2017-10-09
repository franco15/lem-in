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

void	exit_lemin(t_lemin *l)
{
	int	i;

	i = 0;
	while (i < l->rooms)
		ft_memdel((void**)&l->room[i++]);
	free(l->room);
	ft_memdel((void**)&l->end);
	ft_memdel((void**)&l->start);
}
