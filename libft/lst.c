/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:49:23 by coco              #+#    #+#             */
/*   Updated: 2017/06/29 02:49:23 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int		ft_lst_includes(t_lst *lst, char c)
{
	t_lst		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

size_t	ft_lst_len(t_lst *lst)
{
	size_t	i;
	t_lst	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_lst	*ft_lst_new(char data)
{
	t_lst	*new;

	if (!(new = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lst_push_back(t_lst **begin_lst, char data)
{
	t_lst	*lst;

	if (*begin_lst == NULL)
	{
		*begin_lst = ft_lst_new(data);
		return ;
	}
	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	lst->next = ft_lst_new(data);
}

char	*ft_lst_to_s(t_lst *lst)
{
	char		*str;
	size_t		i;
	t_lst		*tmp;
	t_lst		*head;

	tmp = lst;
	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * ft_lst_len(tmp) + 1)))
		return (NULL);
	while (tmp)
	{
		str[i++] = tmp->data;
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	str[i] = '\0';
	return (str);
}
