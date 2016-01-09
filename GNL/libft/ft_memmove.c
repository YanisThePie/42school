/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:18:44 by yismail           #+#    #+#             */
/*   Updated: 2015/12/15 18:07:51 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)malloc(sizeof(*str) * n);
	ft_memcpy(str, src, n);
	ft_memcpy(dest, str, n);
	free(str);
	return (dest);
}
