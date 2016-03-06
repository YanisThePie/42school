/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:56:55 by yismail           #+#    #+#             */
/*   Updated: 2016/03/06 17:24:58 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		how_long_for_n(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

int		to_keep(char **line, char **str_to_keep, char **buf, int *size)
{
	char *the_sub;

	*buf = ft_strnew(BUFF_SIZE);
	*size = 0;
	if (*str_to_keep)
	{
		*line = ft_strnew(0);
		if (ft_strchr(*str_to_keep, '\n'))
		{
			*size = how_long_for_n(*str_to_keep, '\n');
			the_sub = ft_strsub(*str_to_keep, 0, *size);
			*line = ft_strdup(ft_strjoin_free(*line, the_sub));
			*str_to_keep = ft_strdup(ft_strchr(*str_to_keep, '\n') + 1);
			free(the_sub);
			return (1);
		}
		else
			*line = ft_strdup(*str_to_keep);
	}
	else
		*str_to_keep = ft_strnew(BUFF_SIZE);
	return (0);
}

int what_to_do (int *ret, char **str_to_keep, char **buf, char **line) 
{
	int size;

	size = how_long_for_n(*buf, '\0');
	if (ft_strchr(*buf, '\0') && size != BUFF_SIZE)
		*buf = ft_strdup(ft_strjoin_free(*buf, "\n"));
	if (ft_strchr(*buf, '\n'))
	{
		size = how_long_for_n(*buf, '\n');
		if (*line)
			*line = ft_strjoin_free(*line, ft_strsub(*buf, 0, size));
		else
			*line = ft_strsub(*buf, 0, size);
		*str_to_keep = ft_strdup(ft_strchr(*buf, '\n') + 1);
		free(*buf);
		return (*ret);
	}
	else
	{
		if (*line == NULL)
			*line = ft_strnew(1);
		if (*line != NULL)
			*line = ft_strjoin_free(*line, *buf);
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

	if (fd < 0 || line == NULL)
		return (-1);
	ret = to_keep(line, &str_to_keep, &buf, &size);
	if (ret != 0)
	{	
		free(buf);
		return (ret);
	}
	ret = 0;
	while ((ret = (read(fd, buf, BUFF_SIZE) > 0)))
	{
		to_do = what_to_do(&ret, &str_to_keep, &buf, line);
		if (to_do != 0)
			return (to_do);
		free(buf);
		buf = ft_strnew(BUFF_SIZE);
	}
	free(buf);
	return (ret);
}
