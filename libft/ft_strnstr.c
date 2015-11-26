/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:49:45 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 21:06:11 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strnstr (char *str, char *tofind, size_t n)
{
	int a;
	int b;
	int c;
	int cpt;
	int cpt2;

	a = 0;
	b = 0;
	c = 0;
	cpt = 0;
	cpt2 = 0;

	while (str[cpt] != '\0' && cpt < n)
    {
		if (tofind[cpt2] != str[cpt])
		{
			cpt++;
			b++;
		}
		while (tofind[cpt2] == str[cpt] && cpt < n)
		{
			cpt2++;
			cpt++;
			if (tofind[cpt2] == '\0')
			{
				return (str + b);
			}
		}
    }
	return (0);
}