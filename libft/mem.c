/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:13:22 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 11:13:22 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = 0;
	p = malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len-- > 0)
		*s++ = c;
	return (b);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p;
	const char	*s;

	s = src;
	p = dst;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*p++ = *s++;
	return (dst);
}
