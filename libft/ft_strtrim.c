/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:18:20 by yismail           #+#    #+#             */
/*   Updated: 2015/12/01 17:28:47 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strtrim(char const *s)
{
	size_t len;
	char *str_trim;
	
	while (*s != '\0' && *s == '\t' || *s == '\n' || *s == ' ')
		s++;
	len = ft_strlen(s);
	while (len > 0 && (s[len -1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	strim = (char*)malloc(len + 1) * sizeof (*s_trim);
	ft_strncpy(s_trim, s, len);
	s_trim[len] = '\0';
	return(s_trim);
}
