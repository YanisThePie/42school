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

int get_next_line (int const fd, char **line)
{
	int ret;
	char *buf;
	char *membuffer;
	static char *str_to_keep;
	(void)line;

	membuffer = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);

	while ((ret = (read (fd, buf, BUFF_SIZE) > 0)))
	{
		if (ft_strchr(buf, '\n'))
		{
			str_to_keep = (ft_strchr(buf, '\n') + 1);
			*line = 
			//*line = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(str_to_keep));
			//*line = ft_strjoin (str_to_keep, buf);
		}
		if(str_to_keep)
			*line = ft_strjoin(str_to_keep, buf);
		else
			*line = buf;
		ft_putstr(*line); 
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
	ft_putstr(send);
    //get_next_line(fd, &send);
    //ft_putstr(send);
	return (0);
}
