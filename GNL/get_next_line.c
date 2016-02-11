/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:56:55 by yismail           #+#    #+#             */
/*   Updated: 2016/02/10 21:50:11 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *what_is_more(char *str, char* str2)
{
	int i;
	int j;
	char* str_to_send;

	i = 0;
	j = 0;
	while (str[i] == str2[i])
		i++;
	while (str)
		j++;
	str_to_send = (char*) malloc (sizeof(char) * j);
	ft_bzero (str_to_send, j);
	str_to_send = ft_strsub(str, j - i, j);
	return (str_to_send);
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
	static char *str_to_keep = 0;

	newline = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	size = 0;

	while ((ret = (read (fd, buf, BUFF_SIZE) > 0)))
	{
		if (ft_strchr(buf, '\n'))
		{
			ft_putstr(*line);
			size = how_long_for_n (buf);
			*line = ft_strjoin(*line, ft_strsub(buf, 0, size));
			str_to_keep = (ft_strchr(buf, '\n') + 1);
			free(buf);
			return (ret);
		}
		else
		{
			if (*line != NULL)
				*line = ft_strjoin(*line, buf);
			else
			{
				if (str_to_keep)
					*line = ft_strjoin (str_to_keep, buf);
				else
					*line = buf;
			}
		}
		free(buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	return (ret);
}

int main (int argc, char **argv)
{
    char *send;
    int fd;
    int i;

    argc = 1;
    i = 0;

    send = NULL;
    fd = open(argv[1], O_RDONLY);

    get_next_line(fd, &send);
	//ft_putstr(send);
    get_next_line(fd, &send);
    //ft_putstr(send);
	return (0);
}
