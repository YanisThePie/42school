/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:59:42 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 16:03:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin_free(char const *s1, char const *s2)
{
	char    *str;
	size_t  len;

	str = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
		}
	}
	return (str);
}
