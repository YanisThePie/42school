/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:15:21 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 17:05:10 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	str[len] = '\0';
	while (n >= 10)
	{
		str[len - 1] = n % 10 + '0';
		n = (n / 10);
		len--;
	}
	str[len - 1] = n + '0';
	return (str);
}
