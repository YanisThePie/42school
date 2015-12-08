/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:27:40 by yismail           #+#    #+#             */
/*   Updated: 2015/12/08 18:04:11 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		index;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		i = 0;
		index = 0;
		while (s[i] != '\0')
		{
			str[i] = f(index, s[i]);
			i++;
			index++;
		}
		return (str);
	}
	return (NULL);
}
