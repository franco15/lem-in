/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:01:58 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 15:01:58 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*c;
	unsigned int	i;

	i = 0;
	if (s && (c = ft_memalloc(len + 1)))
	{
		while (s[start] != '\0' && len--)
			c[i++] = s[start++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p;
	size_t	l;

	l = ft_strlen(src);
	p = dst;
	if (len > l)
	{
		while (*src)
		{
			*p++ = *src++;
			len--;
		}
		while (len-- > 0)
			*p++ = '\0';
	}
	else
		while (len-- > 0)
			*p++ = *src++;
	return (dst);
}
