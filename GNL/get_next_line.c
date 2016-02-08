/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:24:01 by yismail           #+#    #+#             */
/*   Updated: 2016/02/03 18:58:11 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 5
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *keep_str_tmp (char *str, char *str2)
{
	char *to_keep;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str && j < BUFF_SIZE)
	{
		while (str[i] == str2[i] && str[i] != '\0' && str2[i]!= '\0')
		{
			i++;
		}
		j++;
	}
	to_keep = ft_strsub(str, i, j);
	return (to_keep);
}

char * check_for_new_line (char *str_buf, int *j)
{
	char *str_tmp;
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	str_tmp = NULL;
	while (str_buf[i] != '\n' && str_buf[i] != '\0')
	{
		i++;
	}
	if (str_buf[i] == '\n')
	{
		str_tmp = malloc (sizeof(char) * (i + 1));
		ft_strncpy(str_tmp, str_buf, i);
		str_tmp[i] = '\0';
		while (i < BUFF_SIZE)
		{
			i++;
			cpt++;
		}
		*j = (i - cpt);
	}
	return (str_tmp);
}

int get_the_buffer(int const fd, char **line, char **membuffer_true, int *j)
{
  char buf[BUFF_SIZE + 1];
  int r;
  int i;
  char *newline;
  char *membuffer;
  
  i = *j;
  newline = NULL;
  membuffer = ft_strnew(0);
  while ((r = read (fd, buf, BUFF_SIZE)) > 0)
  {
	  buf[r] = '\0';
	  membuffer = ft_strjoin(membuffer, buf);
	  // ft_strjoinfree? ne pas oubier de free membuffer avant
	  //d'ecraser
	  newline = check_for_new_line(membuffer, &i);
	  if (  newline != NULL)
	  {
		  *line = newline;
		  *j = i;
		  *membuffer_true = membuffer;
		  return(1);
	  }
  }
  return (r);
}
int get_next_line (int const fd, char **line)
{
	int ret;
	char *membuffer;
	static char *str_to_keep = 0;
	int i;

	i = 0;
	membuffer = ft_strnew(0);
	*line = ft_strnew(0);
	ret = get_the_buffer(fd, line, &membuffer, &i);
	if (str_to_keep && ret > 0)
	{
		//verifier si \n dans str_to_keep au deuxieme passage,
		//gerer le deuxieme passage absolument.
		*line = ft_strcat (str_to_keep, *line);
		str_to_keep = NULL;
	}
	else
	{
		if (fd > 0)
			return (ret);
		str_to_keep = keep_str_tmp(membuffer, *line);
	}
	free(membuffer);
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
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	return (0);
}
