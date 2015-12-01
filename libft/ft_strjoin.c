/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:59:42 by yismail           #+#    #+#             */
/*   Updated: 2015/12/01 16:12:41 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strjoin (char const *s1, char const *s2)
{
	char *str;
	
	str = ft_strnew(ftstrlen(s1) + ft_strlen (s2));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
