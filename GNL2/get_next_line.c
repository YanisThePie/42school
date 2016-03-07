/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:00:22 by yismail           #+#    #+#             */
/*   Updated: 2016/03/07 12:16:25 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     how_long_for(char *str, char c)
{
    int     i;

    i = 0;
    while (str[i] != c)
        i++;
    return (i);
}

int str_to_keep ()
{
	const char *str_to_keep;
	char *to_send;
	int size;

	if (str_to_keep)
	{
		if (ft_strchr (str_to_keep, '\n'))
		{
			size = how_long_for (str_to_keep, '\n');
			to_send = ft_strsub(str_to_keep, 0, size); // if \n in str_to_keep, send until it, and keep the rest.
			str_to_keep = ft_strdup(ft_strchr(str_to_keep, '\n') + 1);
			return (to_send);
		}
		else
			return (str_to_keep);
	}
}

char *read_the_buffer(int fd)
{
	char *buf;
	char *buf_joined;

	*buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		if (ft_strchr(*buf, '\n'))// if we found a \n, stop the read.
			return (*buf);
		else
		{
			buf_joined = (buf_joined == NULL) ? ft_strnew(0) : buf_joined;
			buf_joined = ft_strjoin_free(*buf_joined, *buf);// we join buffers, or we create one if doesnt exist.
		}
	}
	return (*buf);// If Read is over, return the buffer.
}
int get_next_line(int const fd, char **line)
{
	char *keeped;
	char *buf;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = read_the_buffer(fd);
	if (BUFF_SIZE != ft_strlen(buf))
	keeped = str_to_keep ();
	*line = ft_strjoin_free(keeped, buf)
}
