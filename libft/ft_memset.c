/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:32:05 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:33:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t		i;

	i = 0;
	str = (unsigned char *)b;
	while (len > 0)
	{
	  str[i] = (unsigned char)c;
		  i++;
		  len--;
	}
	return (b);
}
