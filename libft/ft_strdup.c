/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:54:17 by yismail           #+#    #+#             */
/*   Updated: 2015/12/15 18:28:45 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		j;
	int		i;
	char	*cpy;

	i = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	j = 0;
	while (j < i)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
