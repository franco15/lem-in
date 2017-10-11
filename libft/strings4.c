/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:52:00 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/10 15:52:01 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**r;

	if (!s)
		return (0);
	i = 0;
	k = ft_countwords(s, c);
	if (!(r = (char**)ft_memalloc(sizeof(char*) * (k + 1))))
		return (0);
	while (i < k)
	{
		while (*s && *s == c)
			s++;
		r[i] = ft_strndup(&*s, ft_wordlen(&*s, c));
		while (*s && *s != c)
			s++;
		i++;
	}
	return (r);
}
