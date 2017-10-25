/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 04:24:18 by coco              #+#    #+#             */
/*   Updated: 2017/10/20 04:24:19 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_qa(void)
{
	int		ret;
	char	*line;

	if (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		while (line[0] == '#')
		{
			ft_memdel((void**)&line);
			if (get_next_line(0, &line) == -1)
			{
				line = 0;
				break ;
			}
		}
	}
	ret = (line && *line != '\0') ? ft_atoi(line) : 0;
	ft_memdel((void**)&line);
	return (ret);
}
