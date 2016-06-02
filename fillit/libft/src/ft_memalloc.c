/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:04:50 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/28 19:26:47 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t len)
{
	char	*new;
	size_t	i;

	new = NULL;
	i = 0;
	new = (char*)malloc(len * sizeof(*new));
	if (!new)
	{
		return (NULL);
	}
	while (i < len)
	{
		new[i] = '\0';
		i++;
	}
	return ((void*)new);
}
