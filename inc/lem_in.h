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

typedef struct		t_room
{
	int				x;
	int				y;
	int				command;
	int				wait;
	int				ant;
	char			*name;
	t_list			*path;
}					t_room;

typedef struct		s_ant
{
	int				which_ant;
	int				did_turn;
	t_room			*room;
	t_room			*last;
}					t_ant;

typedef struct		s_lemin
{
	int				qa; //quantity of ants
	int				moves;
	int				rooms_kewl;
	t_ant			*ants; // list of ants
	t_list			*rooms; //room list
	t_list			*path; // path list
}					t_lemin;

/*
** lem_in.c
*/

/*
** ants.c
*/
int					get_qa(void);

/*
** main.c
*/
int					main(int ac, char **av);

/*
** parse.c
*/
int					read_file(t_lemin *l);
t_ant				*start_ants(t_list *rooms, int ants);

/*
** utils.c
*/
int					is_room(char *line);
int					is_link(t_list *rooms, char *line);
t_room				*get_command(t_list *rooms, int i);

#endif
