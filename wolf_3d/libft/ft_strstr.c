/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:53:32 by yismail           #+#    #+#             */
/*   Updated: 2015/12/22 13:05:34 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *tofind)
{
	int		cpt;
	int		cpt2;
	char	*s1;

	cpt = 0;
	cpt2 = 0;
	s1 = (char*)str;
	if (s1 && tofind)
	{
		if (!*tofind)
			return (s1);
		while (s1[cpt])
		{
			cpt2 = 0;
			while (tofind[cpt2] == s1[cpt + cpt2])
			{
				if (!(tofind[cpt2 + 1]))
					return (s1 + cpt);
				cpt2++;
			}
			cpt++;
		}
	}
	return (NULL);
}
