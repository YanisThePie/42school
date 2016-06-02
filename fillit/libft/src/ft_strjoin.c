/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:23:52 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 18:43:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	size = 0;
	len_s1 = 0;
	len_s2 = 0;
	join = NULL;
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		size = len_s1 + len_s2 + 1;
		join = ft_strnew(size);
		if (!join)
		{
			return (NULL);
		}
		ft_strncpy(join, s1, len_s1);
		ft_strcpy(join + len_s1, s2);
	}
	return (join);
}
