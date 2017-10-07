/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:46:09 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 19:46:10 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

static void		set_color_fd(int c, int fd)
{
	ft_putstr_fd("\033[", fd);
	ft_putnbr_fd(c, fd);
	ft_putchar_fd('m', fd);
}

static void		putcstr_fd(char const *s, size_t col, int fd)
{
	set_color_fd(col, fd);
	ft_putstr_fd(s, fd);
	set_color_fd(0, fd);
}

/*
** ft_printfcolor("%s", "qp", 97); 97 = whito
*/

void			ft_printfcolor_fd(int fd, const char *format, ...)
{
	va_list p;
	char	*tmp;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				putcstr_fd(va_arg(p, char*), va_arg(p, size_t), fd);
			else if ((*(format + 1)) == 'd')
			{
				putcstr_fd(tmp = ft_itoa_base(va_arg(p, int), 10),
				va_arg(p, size_t), fd);
				ft_memdel((void**)&tmp);
			}
			format += 1;
		}
		else
			write(fd, format, 1);
		format += 1;
	}
	va_end(p);
}

void			ft_printf_fd(int fd, const char *format, ...)
{
	va_list p;
	char	*str;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				ft_putstr_fd(va_arg(p, char*), fd);
			else if ((*(format + 1)) == 'd')
			{
				str = ft_itoa_base(va_arg(p, int), 10);
				ft_putstr_fd(str, fd);
				ft_memdel((void**)&str);
			}
			else if ((*(format + 1)) == 'c')
				ft_putchar_fd(va_arg(p, int), fd);
			format += 1;
		}
		else
			write(fd, format, 1);
		format += 1;
	}
	va_end(p);
}
