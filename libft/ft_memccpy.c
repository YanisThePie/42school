/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:08:13 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:25:11 by yismail          ###   ########.fr       */
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
	while (str && i < n && str[i] != c)
	{
		str2[i] = str[i];
		i++;
	}
	return (dest);
}
