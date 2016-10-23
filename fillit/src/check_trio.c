/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:58:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/21 12:09:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_line(char **str)
{
	int	i;
	int	nb_diez;

	i = 0;
	nb_diez = 0;
	if (!str || !*str)
		return (0);
	while (ft_check_charset(**str, ".#"))
	{
		if (**str == '#')
			nb_diez++;
		(*str)++;
		i++;
	}
	if (**str == '\n' && i == 4)
	{
		(*str)++;
		return (nb_diez);
	}
	return (-1);
}

static	int	check_diez(char *str)
{
	int	nb_diez;
	int	ret;
	int	i;

	nb_diez = 0;
	ret = 1;
	i = 0;
	while (i < 4 && ret != -1)
	{
		ret = check_line(&str);
		nb_diez += ret;
		i++;
	}
	if (nb_diez != 4)
		return (0);
	return (1);
}

static int	check_valid(char *str)
{
	int	env;
	int	i;

	env = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i + 1 < 20)
				if (str[i + 1] == '#')
					env++;
			if (i + 5 < 20)
				if (str[i + 5] == '#')
					env++;
		}
		i++;
	}
	if (env == 3 || env == 4)
		return (1);
	return (0);
}

int			check_trio(char *str, int nb_trio)
{
	int		nb_diez;

	nb_diez = 4;
	if (!(nb_diez = check_diez(str)))
		return (0);
	if (!check_valid(str))
		return (0);
	nb_trio++;
	str += 20;
	if (*str == '\n')
		return (check_trio(str + 1, nb_trio));
	else if (!*str)
		return (nb_trio);
	else
		return (0);
}
