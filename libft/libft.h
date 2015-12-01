/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:13:04 by yismail           #+#    #+#             */
/*   Updated: 2015/12/01 15:12:00 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
#include <string.h>
#include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void    ft_bzero(void *s, size_t n);
int     ft_isdigit(int c);
int     ft_isalpha(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
char    *ft_strcat(char *dest, char *src);
char    *ft_strchr(char *s, int c);
int     ft_strcmp(char *s1, char *s2);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strdup(char *str);
size_t	ft_strlen(char *c);
size_t  ft_strlcat(char *dest, char *src, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memccpy(void *dest, const void *src, int c, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memset(void *b, int c, size_t len);
char    *ft_strncat(char *dest, char *src, size_t n);
int     ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *str, char *tofind, size_t n);
char    *ft_strrchr(char *s, int c);
char    *ft_strstr(char *str, char *tofind);
int     ft_tolower(int c);
int     ft_toupper(int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
void	ft_memdel (void **ap);
void    *ft_memalloc(size_t size);
char    *ft_strnew(size_t size);
void	ft_strdel (char **as);
void	ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void(*f)(unsigned int, char *));
#endif
