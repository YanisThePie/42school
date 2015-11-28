/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:47:29 by yismail           #+#    #+#             */
/*   Updated: 2015/11/28 20:53:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    char *str;
    char *str2;
    size_t i;

    i = 0;
    str = (char *)s;
    while (str && i < n)
    {
		if (str[i] == c)
			return (str + i);
			i++;
    }
    return (NULL);
}
