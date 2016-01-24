
#define BUFF_SIZE 10
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
	while (str[i] != '\0' && j < BUFF_SIZE)
	{
		while (str[i] == str2[i])
			i++;
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
		i++;
	if (str_buf[i] == '\n')
	{
		str_tmp = malloc (sizeof(char) * i);
		ft_strncpy(str_tmp, str_buf, i);
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
  i = 0;
  newline = NULL;
  membuffer = ft_strnew(BUFF_SIZE);
  while ((r = read (fd, buf, BUFF_SIZE)))
  {
	  if (r == -1)
		  return (-1);
	  buf[r] = '\0';
	  membuffer = ft_strjoin (membuffer, buf);
	  newline = check_for_new_line(membuffer, &i);
	  if (newline != NULL)
	  {
		  *line = newline;
		  *j = i;
		  *membuffer_true = membuffer;
		  return(1);
	  }
  }
  return (0);
}
int get_next_line (int const fd, char **line)
{
	int ret;
	char *membuffer;
	static char *str_to_keep = 0;
	int i;

	membuffer = ft_strnew(1);
	*line = ft_strnew(1);
	ret = get_the_buffer (fd, line, &membuffer, &i);
	if (str_to_keep != NULL)
	{
		ft_putnbr(3);
		ft_putstr(*line);
		*line = ft_strjoin (str_to_keep, *line);
		ft_putnbr(4);
		ft_putstr(*line);
		ft_putnbr(5);
		ft_putstr(str_to_keep);
	}
	str_to_keep = keep_str_tmp(membuffer, *line);
	return (0);
}


int main (int argc, char **argv)
{
	char *send;
	int fd;
	argc = 1;

	send = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &send);
	//ft_putstr(send);
	get_next_line(fd, &send);
	//ft_putstr(send);
	get_next_line(fd, &send);
	return (0);
}
