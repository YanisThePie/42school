/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:18:20 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 18:44:54 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str_trim;

	if (s == NULL)
	  return (NULL);

	while ((*s != '\0' && *s == '\t') || *s == '\n' || *s == ' ')
		s++;
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n' ||
	s[len - 1] == '\t'))
		len--;
	if(!(str_trim = (char*)malloc((len + 1) * sizeof(*str_trim))))
	return (0);
	ft_strncpy(str_trim, s, len);
	str_trim[len] = '\0';
	return (str_trim);
}
