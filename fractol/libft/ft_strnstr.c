/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:49:45 by yismail           #+#    #+#             */
/*   Updated: 2015/12/15 18:14:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *tofind, size_t n)
{
	int		b;
	size_t	cpt;
	int		cpt2;

	b = 0;
	cpt = 0;
	cpt2 = 0;
	if (*tofind == '\0')
		return ((char*)str);
	while (str[cpt] != '\0' && cpt < n)
	{
		if (tofind[cpt2] != str[cpt])
		{
			cpt++;
			b++;
		}
		while (tofind[cpt2] == str[cpt] && cpt < n)
		{
			cpt2++;
			cpt++;
			if (tofind[cpt2] == '\0')
				return (str + b);
		}
	}
	return (0);
}
