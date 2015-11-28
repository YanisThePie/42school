/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:34:14 by yismail           #+#    #+#             */
/*   Updated: 2015/11/28 17:25:28 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_isalpha(int c)
{
    if (c >= 65 && c <= 90)
        return (1);
    if (c >= 97 && c <= 122)
        return (1);
    return (0);
}

int     ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    if (c < 48 && c > 57)
        return (0);
	return (0);
}

int ft_isalnum (int c)
{
	if (!ft_isdigit(c) && !ft_isalpha(c))
		return (0);
	return (1);
}
