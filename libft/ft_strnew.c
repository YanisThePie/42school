/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:26:26 by yismail           #+#    #+#             */
/*   Updated: 2015/12/01 13:41:05 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	int i;

	i = 0;
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{	
		str[i] = '\0';
		i++;
	}
	return (str);
}