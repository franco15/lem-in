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
	int				p;
	int				ants;
	int				whereami;
	int				links; //edges
	int				rooms; //vertices
	int				**lonk; //1 & 0 table
	char			*end;
	char			*start;
	char			**path;
	char			**room;
	char			***link;
}					t_lemin;

/*
** lem_in.c
*/
void				lem_in(t_lemin *l, int x, int y);

/*
** link.c
*/
int					get_link(t_lemin *l, int i);
void				check_link(t_lemin *l, int n);

/*
** main.c
*/
int					main(void);

/*
** parse.c
*/
int					get_room(t_lemin *l, char *s);
void				lonks(t_lemin *l);
void				get_rooms(t_lemin *l, int i);

/*
** utils.c
*/
void				free_lemin(t_lemin *l);
int					is_end(t_lemin *l, int n);
int					is_valid(t_lemin *l, int n);

#endif
