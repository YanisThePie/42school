/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:00:22 by yismail           #+#    #+#             */
/*   Updated: 2016/03/06 18:37:33 by yismail          ###   ########.fr       */
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

char *read_the_buffer(int fd)
{
	char *buf;
	char *buf_joined;

	*buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		if (ft_strchr(*buf, '\n'))
			return (*buf);
		else
		{
			buf_joined = (buf_joing == NULL) ? ft_strnew(0) : buf_joined;
			buf_joined = ft_strjoin_free(*buf_joined, *buf);
		}
	}
}
int get_next_line(int const fd, char **line)
{
	char *to_keep;

	if (fd < 0 || line == NULL)
		return (-1);
	read_the_buffer(fd);
	
}
