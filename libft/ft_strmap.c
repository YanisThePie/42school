/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:17:17 by yismail           #+#    #+#             */
/*   Updated: 2015/12/01 15:25:46 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	int i;

	if (s && f)
	{
		str = ft_strnew(strlen(s));
		i = 0;
		while (s[i] != '\0')
		{	
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
