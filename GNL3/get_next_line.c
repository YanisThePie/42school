/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:12:15 by yismail           #+#    #+#             */
/*   Updated: 2016/03/11 00:25:00 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_read (char **buffer, char **tmp, int fd)
{
	int ret;
	int i;
	char *pos;
	char buf[BUFF_SIZE + 1];

	i = 0;
	if ((pos = ft_strchr(*buffer, '\n')))
	{
		pos[0] = '\0';
		(*pos) ++;
		*tmp = ft_strdup(pos);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*buffer = ft_strjoin_free(*buffer, buf);
		if ((pos = strchr(*buffer, '\n')))
		{
			pos[0] = '\0';
			pos++;
			*tmp = ft_strdup(pos);
			return (1);
		}
	}
	if (i == 1)
		return (1);
	if (ret == 0)
		return (0);
	if (ret == -1)
		return (-1);
	return (1);
}

int get_next_line(int const fd, char **line)
{
	static char *tmp;
	char		*buffer;
	int			ret;
	
	buffer = ft_strnew(1);
	if (fd < 0 || !line)
		return (-1);
	if (tmp)
		buffer = ft_strjoin_free(tmp, buffer);
	ret = ft_read(&buffer, &tmp, fd);
	*line = ft_strdup(buffer);
	return (ret);
	
} 
