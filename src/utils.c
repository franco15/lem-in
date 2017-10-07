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

// void	get_ants(t_lemin *l)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
// 	while (i < l->flen)
// 	{
//
// 	}
// }

int		get_file_len(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	close(fd);
	return (i);
}
