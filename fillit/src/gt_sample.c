/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_sample.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:22:22 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/11 17:53:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static ssize_t	gt_ssize_file(int fd)
{
	char	buf[1];
	ssize_t	ret;
	ssize_t	i;

	*buf = '\0';
	ret = 1;
	i = 0;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			close(fd);
			return (ret);
		}
		else if (!ret)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static ssize_t	gt_chfile(const char *file)
{
	int		fd;
	ssize_t	file_s;

	fd = 0;
	file_s = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	file_s = gt_ssize_file(fd);
	if (file_s == -1)
	{
		return (-1);
	}
	close(fd);
	return (file_s);
}

static char		*gt_str(const char *file, ssize_t file_s)
{
	char	*buf;
	int		fd;
	ssize_t	ret;

	buf = NULL;
	fd = 0;
	ret = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error open");
		return (NULL);
	}
	buf = ft_strnew(file_s);
	ret = read(fd, buf, file_s);
	if (ret != file_s)
	{
		ft_putstr("error read");
		return (NULL);
	}
	close(fd);
	return (buf);
}

char			*gt_sample(char *sample_name)
{
	char	*str;
	ssize_t	file_s;

	file_s = 0;
	str = NULL;
	file_s = gt_chfile(sample_name);
	if (!file_s)
		return (NULL);
	str = gt_str(sample_name, file_s);
	if (!file_s)
		return (NULL);
	return (str);
}
