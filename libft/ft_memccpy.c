/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:08:13 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 15:58:36 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	str = (char *)src;
	str2 = (char *)dest;
	while (i < n)
	{
		str2[i] = str[i];
		if ((char)c == str2[i])
			return ((void*)&str2[i + 1]);
		i++;
	}
	return (NULL);
}
