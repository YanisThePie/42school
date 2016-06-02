/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:47:24 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 09:41:56 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				i_value(char *str1)
{
	int			i;

	i = 0;
	while (str1[i] == ' ' || (str1[i] == '\t') || (str1[i] == '\v')
	|| (str1[i] == '\n') || (str1[i] == '\f') || (str1[i] == '\r'))
		i++;
	return (i);
}

long int		ft_atoi(const char *str)
{
	int			i;
	long int	nbr;
	int			sign;
	char		*str1;

	if (!str)
		return (0);
	sign = 1;
	nbr = 0;
	str1 = (char*)str;
	i = i_value(str1);
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
