/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:47:24 by yismail           #+#    #+#             */
/*   Updated: 2015/12/10 19:17:18 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		sign;
	char	*str1;

	if (!str)
		return (0);
	sign = 1;
	nbr = 0;
	i = 0;
	str1 = (char*)str;
	while (str1[i] == ' ' || (str1[i] == '\t') || (str1[i] == '\v')
	|| (str1[i] == '\n') || (str1[i] == '\f') || (str1[i] == '\r'))
		i++;
	if (str1[i] == '-')
	{
		sign = -1;
		nbr = (nbr * 10);
		i++;
	}
	else if (str1[i] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - 48);
	return (sign * nbr);
}
