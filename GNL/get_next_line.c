
#define BUFF_SIZE 8
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char * check_for_new_line (char *str_buf, int *j)
{
	char *str_tmp;
	int i;

	i = *j;
	str_tmp = NULL;
	i = 0;
	while (str_buf[i] != '\n' && str_buf[i] != '\0' && str_buf)
	{
		i++;
	}
	if (str_buf[i] == '\n')
	{
		str_tmp = malloc (sizeof(char) * i);
		strncpy(str_tmp, str_buf, i);
	}
	*j = i;
	return (str_tmp);
	}

int get_the_buffer(int const fd, char **line, char *membuffer, int *j)
{
  char buf[BUFF_SIZE + 1];
  (void)line;
  int r;
  int cpt;
  int i;
  char *newline;
  static char *str_tmp;
  
  i = *j;
  cpt = 0;
  i = 0;
  line = NULL;
  str_tmp = NULL;
  newline = NULL;
  membuffer = (char*)malloc (sizeof(char) * (BUFF_SIZE + sizeof(str_tmp)));
  while ((r = read (fd, buf, BUFF_SIZE)))
  {
	  if (r == -1)
		  return (-1);
	  membuffer = ft_strjoin (membuffer, buf);
	  newline = check_for_new_line(membuffer, &i);
	  if (newline != NULL)
	  {
		  *j = i;
		  ft_putstr(newline);
		  //ft_putstr(membuffer);
		  return(1);
	  }
	  //ft_putstr(membuffer);
  }
  return (0);
}
int get_next_line (int const fd, char **line)
{
	int ret;
	//char *str_to_print;
	char *membuffer;
	int i;

	membuffer = ft_strnew(1);
	ret = get_the_buffer (fd, line, membuffer, &i);
	ft_putnbr(i);
	ft_putstr(membuffer);
	//str_to_keep = keep_str_tmp(membuffer);
	//str_to_print = ft_strjoin(str_to_keep, membuffer);
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
	return (0);
}
