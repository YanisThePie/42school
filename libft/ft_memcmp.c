/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:35:12 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 15:09:02 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str;
	char	*str2;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (j);
	while ((str[i] == str2[i]) && str[i] && i < (n - 1))
		if (i < (n - 1))
			i++;
	j = (str[i] - str2[i]);
	return (j);
}
