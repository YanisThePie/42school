/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:56:55 by yismail           #+#    #+#             */
/*   Updated: 2016/02/11 18:01:12 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_fd(int fd)
{
	if (fd < 0)
		return (-1);
	return (0);
}

int how_long_for_n (char* str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
int get_next_line (int const fd, char **line)
{
	int ret;
	int size;
	char *buf;
	char *newline;
	static char *str_to_keep;

	if (check_fd(fd) == -1)
		return (-1);
	newline = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	size = 0;
	if (str_to_keep)	
	{
		*line = ft_strnew(0);
		if (ft_strchr(str_to_keep, '\n'))
		{
			size = how_long_for_n (str_to_keep);
			*line = ft_strdup(ft_strjoin(*line, ft_strsub(str_to_keep, 0, size)));
			str_to_keep = ft_strdup(ft_strchr(str_to_keep, '\n') + 1);
			return (1);
		}
		else
			*line = ft_strdup(str_to_keep);
	}
	else
		str_to_keep = ft_strnew(BUFF_SIZE);
	while ((ret = (read (fd, buf, BUFF_SIZE) > 0)))
	{
		if (ft_strchr(buf, '\n'))
		{
			size = how_long_for_n (buf);
			if (*line)
				*line = ft_strjoin_free(*line, ft_strsub(buf, 0, size));
			else 
				*line = ft_strsub(buf, 0, size);
			str_to_keep = ft_strdup(ft_strchr(buf, '\n') + 1);
			free(buf);
			return (ret);
		}
		else
		{
			if (*line == NULL)
				*line = ft_strnew(1);
			if (*line != NULL)
				*line = ft_strjoin_free(*line, buf);
		}
		free(buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	return (ret);
}
/*
int main (int argc, char **argv)
{
    char *send;
    int fd;
    int i;

    argc = 1;
    i = 0;

    send = NULL;
    fd = open(argv[1], O_RDONLY);

    while(get_next_line(fd, &send) > 0)
	{
		if (send != NULL)
		{	
			ft_putendl(send);
			free(send);
			send = NULL;
		}
	}
//	get_next_line(fd, &send);
	//   ft_putendl(send);
	return (0);
}
*/
