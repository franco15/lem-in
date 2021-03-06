/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:39:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 15:39:44 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace(int c)
{
	return (c == 32 || c == 9 || c == 11 || c == 13 || c == 10 || c == '\f');
}

void	ft_error(char *s)
{
	ft_printf_fd(2, "DED: %s\n", s);
	exit(EXIT_FAILURE);
}

int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s && *s != c)
			s++;
		if (!*s)
			return (i);
		s++;
	}
	return (i);
}

int		ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		else
		{
			s++;
			i++;
		}
	}
	return (i);
}
