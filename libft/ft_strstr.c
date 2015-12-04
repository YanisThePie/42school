/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:53:32 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:53:57 by yismail          ###   ########.fr       */
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
	if (str == NULL || tofind == NULL)
	  return (NULL);
	while (str[cpt] != '\0')
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
				return (str + b);
		}
	}
	return (0);
}
