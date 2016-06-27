/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:18:52 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 16:05:40 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	int		j;
	int		k;

	j = ft_strlen(s) + 1;
	i = 0;
	k = 0;
	while (--j)
	{
		if (s[j] == (char)c)
			return ((char*)s + j);
	}
	if (s[j] == (char)c)
		return ((char*)s + j);
	return (NULL);
}
