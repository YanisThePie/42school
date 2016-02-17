/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:56:55 by yismail           #+#    #+#             */
/*   Updated: 2016/02/17 23:05:40 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		how_long_for_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		to_keep(char ***line, char **str_to_keep, char **buf, int *size)
{
	*buf = ft_strnew(BUFF_SIZE);
	*size = 0;
	if (*str_to_keep)
	{
		**line = ft_strnew(0);
		if (ft_strchr(*str_to_keep, '\n'))
		{
			*size = how_long_for_n(*str_to_keep);
			**line = ft_strdup(ft_strjoin_free(**line, ft_strsub(*str_to_keep, 0, *size)));
			*str_to_keep = ft_strdup(ft_strchr(*str_to_keep, '\n') + 1);
			free(*buf);
			return (1);
		}
		else
			**line = ft_strdup(*str_to_keep);
	}
	else
		*str_to_keep = ft_strnew(BUFF_SIZE);
	return (0);
}

int what_to_do (int *ret, char **str_to_keep, char **buf, char ***line) 
{
	int size;

	if (ft_strchr(*buf, '\n'))
	{
		size = how_long_for_n(*buf);
		if (**line)
			**line = ft_strjoin_free(**line, ft_strsub(*buf, 0, size));
		else
			**line = ft_strsub(*buf, 0, size);
		*str_to_keep = ft_strdup(ft_strchr(*buf, '\n') + 1);
		free(*buf);
		return (*ret);
	}
	else
	{
		if (**line == NULL)
			**line = ft_strnew(1);
		if (**line != NULL)
			**line = ft_strjoin_free(**line, *buf);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	int				size;
	int				to_do;
	char			*buf;
	static char		*str_to_keep;

	if (fd == -1)
		return (-1);
	ret = to_keep(&line, &str_to_keep, &buf, &size);
	if (ret != 0)
	{
		free(buf);
		return (ret);
	}
	ret = 0;
	while ((ret = (read(fd, buf, BUFF_SIZE) > 0)))
	{
		to_do = what_to_do(&ret, &str_to_keep, &buf, &line);
		if (to_do != 0)
			return (to_do);
		free(buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	if (ret == 0 && str_to_keep == NULL)
		free(str_to_keep);
	free(buf);
	return (ret);
}
