
#define BUFF_SIZE 10
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void  print_str(char *buf, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar(buf[j]);
		j++;
	}
}

char * check_for_new_line (char *str_buf, int i)
{
	char *str_tmp;
	int cpt;
	int j;

	cpt = 0;
	j = 0;
	str_tmp = NULL;
	while (str_buf[i] != '\n' && str_buf != '\0')
		i++;
	if (str_buf[i] == '\n')
	{
		while (cpt < i)
		{
			str_tmp[cpt] = str_buf[cpt];
			cpt++;
		}
	}
	return(str_tmp);
}

int get_the_buffer(int const fd, char **line)
{
  char buf[BUFF_SIZE + 1];
  (void)line;
  int r;
  int cpt;
  int i;
  static char *str_tmp;

  cpt = 0;
  i = 0;
  membuffer = NULL;
  membuffer = (char*)malloc (sizeof(char) * (BUFF_SIZE + sizeof(str_tmp)));
  while ((r = read (fd, buf, BUFF_SIZE)))
  {
	  if (r == -1)
		  return (-1);
	  membuffer = ft_strjoin (membuffer, buf);
	  if (check_for_new_line(membuffer, 0) == 1)
		  return(1);
  }
  return (0);
}
int get_next_line (int const fd, char **line)
{
	int ret;
	char *membuffer;
	char *str_to_print;
	char *str_tmp;
	
  ret = get_the_buffer (fd, send);
  str_tmp = keep_str_tmp(membuffer);
  str_to_print = ft_strjoin(str_tmp, membuffer);
  return (0);
}


int main (int argc, char **argv)
{
	char **send;
	int fd;
	argc = 1;

	send = NULL;
	fd = open(argv[1], O_RDONLY);
	
	
/*
while ((r = read (fd, buf, BUFF_SIZE)))
{
	ft_putnbr (fd);
	buf[r] = '\0';
	if (r == -1)
		return (0);
	if (buf[i] == '\n')
	{
		printf("3\n");
		str_tmp = malloc(sizeof BUFF_SIZE - i);
		while (i < BUFF_SIZE)
		{
			str_tmp[cpt] = buf[i];
			cpt++;
			i ++;
		}
		i = (i - cpt);
		if(!(str = malloc(sizeof(char) * (i + cpt))))
			return (-1);
		while (j < i && buf[j] != '\n')
		{
			str[j] = buf[j];
			j++;
		}
		*line = str;
		printf ("%s", str);
		return (1);
	}
	printf("%d\n",i);
	i++;
}
return (0);
*/
