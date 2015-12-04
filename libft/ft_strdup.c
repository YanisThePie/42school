/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:54:17 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:44:25 by yismail          ###   ########.fr       */
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
	cpy = (char *)malloc(j * sizeof(*str));
	while (i < j && str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}
