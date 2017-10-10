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
	int				links; //edges
	int				rooms; //vertices
	char			*end;
	char			*start;
	char			**link;
	char			**room;
}					t_lemin;

/*
** lem_in.c
*/
void				lem_in(t_lemin *l);

/*
** main.c
*/
int					main(void);

/*
** parse.c
*/
void				get_rooms(t_lemin *l, int i);

/*
** utils.c
*/
void				exit_lemin(t_lemin *l);

#endif
