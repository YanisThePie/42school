/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:18:44 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:32:48 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*str2;
	char	*str3;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char*)src;
	j = ft_strlen(str);
	str2 = (char*)malloc(n * sizeof(*str));
	while (str && i < n)
	{
		str2[i] = str[i];
		i++;
	}
	str3 = (char *)dest;
	i = 0;
	while (str2 && i < n)
	{
		str3[i] = str2[i];
		i++;
	}
	free(str2);
	return (dest);
}
