/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:45:13 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/26 16:45:38 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_i;
	const char	*src_i;
	char		temp[len + 1];

	i = 0;
	dst_i = (char*)dst;
	src_i = (const char*)src;
	temp[len] = 0;
	ft_memcpy(temp, src_i, len);
	while (i < len)
	{
		dst_i[i] = temp[i];
		i++;
	}
	return (dst);
}
