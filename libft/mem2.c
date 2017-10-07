/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:44:56 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 11:44:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_realloc(void *ptr, size_t size, size_t newsize)
{
	void	*new;

	if (ptr && newsize && size)
	{
		new = ft_memalloc(newsize);
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	else
		new = ft_memalloc(newsize);
	return (new);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (d > s)
		while (len--)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
