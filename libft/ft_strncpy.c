/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:20:19 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 15:25:12 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(src);
	while (src[i] != '\0' && i <= n && i <= j)
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] == '\0' && dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
