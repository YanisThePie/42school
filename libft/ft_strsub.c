/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:50:56 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 15:23:57 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	dest = (char *)malloc ((len + 1) * sizeof(*s));
	if (dest == NULL || s == NULL)
		return (NULL);
	ft_strncpy (dest, &(s[start]), len);
	dest[len] = '\0';
	return (dest);
}
