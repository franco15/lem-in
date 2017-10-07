/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:28:54 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 11:28:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(sizeof(char) * (size + 1)));
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if ((dup = ft_strnew(ft_strlen(s1))))
		return (ft_strcpy(dup, s1));
	return (0);
}

void	ft_strdel(char **as)
{
	if (as)
		ft_memdel((void**)as);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (0);
}
