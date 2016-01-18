
#define BUFF_SIZE 100
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

int check_for_new_line (char *str_buf, int i)
{
	char *str_tmp;
	int cpt;
	int j;

	cpt = 0;
	j = 0;
	str_tmp = NULL;
	if (i >= BUFF_SIZE)
		return (0);
	if (str_buf[i] == '\n')
	{
		str_tmp = malloc(sizeof BUFF_SIZE);
		while (j < i)
		{
			str_tmp[cpt] = str_buf[j];
			cpt++;
			j ++;
		}
		ft_putstr(str_tmp);
		free(str_tmp);
		return (1);
	}
	else
		check_for_new_line(str_buf, i + 1);
	//si pas de newline?
	return(0);
}

int get_next_line(int const fd, char **line)
{
  char buf[BUFF_SIZE + 1];
  (void)line;
  int r;
  int cpt;
  int i;
  int ret;
  static char *str_tmp;
  char *membuffer;

  cpt = 0;
  i = 0;
  membuffer = NULL;
  membuffer = (char*)malloc (sizeof(char) * (BUFF_SIZE + sizeof(str_tmp)));
  while ((r = read (fd, buf, BUFF_SIZE)))
  {
	  if (r == -1)
		  return (-1);
	  ret = check_for_new_line(buf, 0);
	  if (ret == 1)
		  ft_putstr("stop");
  }
	 return (0);
}
int main (int argc, char **argv)
{
  char **send;
  int fd;
  int ret;
  argc = 1;

  send = NULL;
  fd = open(argv[1], O_RDONLY);
  ret = get_next_line (fd, send);
   ret = get_next_line (fd, send);
  return (0);
}


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
