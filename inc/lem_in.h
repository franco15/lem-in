/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:39:17 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/06 17:39:17 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/minilibft.h"

typedef struct		s_lemin
{
	int				ants;
	int				links;
	int				rooms;
	char			*end;
	char			*start;
	char			**link;
	char			**room;
}					t_lemin;

/*
** main.c
*/
int					main(int ac, char **av);

/*
** parse.c
*/
void				get_rooms(t_lemin *l, int fd);

/*
** utils.c
*/
void				exit_lemin(t_lemin *l);

#endif
