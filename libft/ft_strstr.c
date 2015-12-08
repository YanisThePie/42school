/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:53:32 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 16:42:31 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *tofind)
{
	int		b;
	int		cpt;
	int		cpt2;

	b = 0;
	cpt = 0;
	cpt2 = 0;
	if (*tofind == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		if (tofind[cpt2] != str[cpt])
		{
			cpt++;
			b++;
		}
		while (tofind[cpt2] == str[cpt])
		{
			cpt2++;
			cpt++;
			if (tofind[cpt2] == '\0')
				return ((char*)str + b);
		}
	}
	return (0);
}
