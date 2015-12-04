/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:47:29 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 18:04:36 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)s))
	  return (NULL);
	i = 0;
	while (i < n)
	{
	  if ((char)c == str[0])
		  return ((void*)str);
		i++;
		str++;
	}
	return (NULL);
}
