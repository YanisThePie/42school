/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:35:12 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 15:59:45 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str;
	const unsigned char		*str2;
	size_t				i;
	int		      		j;

	i = 0;
	j = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 && !s2 && !n)
	  return (0);
	while (n--)
	  {
	    if (str[i] != str2[i])
	      return (str[i] - str2[i]);
	    i++;
	  }
	    return (0);
}
