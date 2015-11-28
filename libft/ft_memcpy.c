/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:51:29 by yismail           #+#    #+#             */
/*   Updated: 2015/11/28 20:02:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *str;
	char *str2;
	size_t i;

	i = 0;
	str = (char *)src;
	str2 = (char *)dest;
	while (str && i < n)
	{
		str2[i] = str[i] ;
		i++;
	}
	return (dest);
}
