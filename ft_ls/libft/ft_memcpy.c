/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:51:29 by yismail           #+#    #+#             */
/*   Updated: 2016/05/18 20:03:09 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	str = (char *)src;
	str2 = (char *)dest;
	
	while (n >8)
	{
		*(uint64_t*)dest++ = *(uint64_t*)src++;
		n -= 8;
	}
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dest);
}
