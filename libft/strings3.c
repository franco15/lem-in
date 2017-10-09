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

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strndup(const char *s1, size_t l)
{
	char	*dup;

	if ((dup = ft_strnew(l)))
		return (ft_strncpy(dup, s1, l));
	return (0);
}

int		ft_str_includes(char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}
