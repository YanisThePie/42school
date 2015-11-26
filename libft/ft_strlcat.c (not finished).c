/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:00:02 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 16:54:58 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_strlcat (char *dest, char *src, size_t n)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	k = 0;
	l = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	if ((i - n) <= 0)
	l = (i - n); 
	while (src[j] != '\0' && j <= n)
    {
		dest[i + j] = src[j];
		j++;
    }
	dest[i + j] = '\0';
	i = 0;

	while (dest[i] != '\0')
		i++;

	i = i - l;
	return(i);
}

int main (void)
{
	int i;
	int j;
	char dest[50] = "bonjour";
	char src[50] = "mondsfhgieshgpeshgespghesgeshpgu";
	char dest2[50] = "bonjour";

	i = ft_strlcat (dest, src, 3);
	printf ("%d\n", i); 
	j = strlcat (dest2, src, 3);
	printf ("%d\n", j);
}

