#define BUFF_SIZE 21
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line(int const fd, char **line)
{
  char buf[BUFF_SIZE + 1];
  char *str;
  char *str_tmp;
  int i;
  int j;
  int r;
  int cpt;
  static int tmp_buffer;

  while ((r = read (fd, buf, BUFF_SIZE)))
  {
       printf ("%s\n", buf);
       buf[r] = '\0';
       if (r == -1)
	 return (0);
       /*          if (buf[i] == '\n')
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
	}*/
       printf("%d\n",i);
    i++;
  }
  return (0);
}
int main (int argc, char **argv)
{
  int r;
  char **send;
  int fd;
  int ret;

  send = NULL;
  fd = open(argv[1], O_RDONLY);
  ret = get_next_line (fd, send);
  //  printf ("%s",*send);
  return (0);
}
