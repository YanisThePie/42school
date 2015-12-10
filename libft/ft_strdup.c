/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:54:17 by yismail           #+#    #+#             */
/*   Updated: 2015/12/10 19:18:14 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		j;
	int		i;
	char	*cpy;

	i = 0;
	j = ft_strlen(str);
	cpy = (char *)ft_strnew(j * sizeof(*str));
	if (cpy == NULL || str == NULL)
		return (NULL);
	while (i < j && str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
