/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:51:31 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 19:18:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char			*str_n;

	str_n = NULL;
	if (str)
	{
		str_n = ft_strnew(len);
		if (!str_n)
		{
			return (NULL);
		}
		ft_strncpy(str_n, str + start, len);
		str_n[len] = '\0';
	}
	return (str_n);
}
