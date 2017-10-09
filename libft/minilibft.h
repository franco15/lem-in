/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:38:14 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 10:38:15 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_lst
{
	struct s_lst	*next;
	char			data;
}					t_lst;

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

/*
** array.c
*/
void				ft_arrdel(void **arr);

/*
** conv.c
*/
char				*ft_itoa_base(long long int n, int b);
int					ft_atoi(char const *str);
int					ft_abs(int a);

/*
** ft_printf_fd.c
*/
void				ft_printfcolor_fd(int fd, const char *format, ...);
void				ft_printf_fd(int fd, const char *format, ...);

/*
** ft_printf.c
*/
void				ft_printfcolor(const char *format, ...);
void				ft_printf(const char *format, ...);

/*
** get_next_line.c
*/
int					get_next_line(const int fd, char **line);

/*
** lst.c
*/
int					ft_lst_includes(t_lst *lst, char c);
size_t				ft_lst_len(t_lst *lst);
t_lst				*ft_lst_new(char data);
void				ft_lst_push_back(t_lst **begin_lst, char data);
char				*ft_lst_to_s(t_lst *lst);

/*
** mem.c
*/
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
** mem2.c
*/
void				*ft_realloc(void *ptr, size_t size, size_t newsize);
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
** put_fd.c
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putcharn_fd(int c, int n, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** put.c
*/
size_t				ft_putstr(char const *s);
void				ft_putnbr(int nb);
size_t				ft_putchar(char c);

/*
** strings.c
*/
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);

/*
** strings2.c
*/
size_t				ft_strlenc(const char *s, char c);
char				*ft_strcpy(char *dst, const	char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);

/*
** strings3.c
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *s1, size_t l);
int					ft_str_includes(char *str, char c);

/*
** xtra.c
*/
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				ft_error(char *s);

#endif
