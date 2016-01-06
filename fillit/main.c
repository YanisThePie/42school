/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:14:38 by jaustry           #+#    #+#             */
/*   Updated: 2016/01/06 20:10:48 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  print_list (t_dlist *lst)
{
	int i;

    while (lst !=  NULL)
    {
		i = 0;
		while (i < 4)
		{
			ft_putstr (lst->content[i]);
			ft_putchar('\n');
			i++;
		}
        lst = lst->next;
    }

    return (0);
}

t_dlist *ft_dlstnew(char **content, size_t content_size)
{
    t_dlist*new;

    if ((new = (t_dlist*)malloc(sizeof(t_dlist))) == NULL)
        return (NULL);
    new->next = NULL;
    if (content == NULL)
    {
        new->content = NULL;
        new->content_size = 0;
    }
    else
    {
//        new->content = malloc(content_size);
		//       if (new->content == NULL)
        //{
		//   free(new);
		//   return (NULL);
        //}
        //ft_memcpy(new->content, content, content_size);
		new->content = content;
        new->content_size = content_size;
    }
    return(new);
}

t_dlist *ft_lstpushback(t_dlist *first, char **tab)
{
	t_dlist		*tmp;

	if (first == NULL)
		first = ft_dlstnew(tab, sizeof(tab));
	else
	{
		tmp = first;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_dlstnew(tab, sizeof(tab));
	}
	return (first);
}

# define SIZE_OF_TETRIMINOS     (21 * sizeof(char))
t_dlist		*get_pieces(int fd)
{
	char	buf[21 +1];
	ssize_t	r;
	char	alpha;
	char	**tab;
	t_dlist	*first;

	alpha = 'A';
	first = NULL;
	while ((r = read(fd, buf, 21)))
	{
		buf[r] = '\0';
		verify_piece(buf);
		verify_n(buf);
		verify_link(buf);
		tab = main_creation(buf, alpha);
		first = ft_lstpushback (first, tab);
		alpha++;
	}
	printf("%s\n", "super");
	return (first);
}
void		verify_piece(char *buf)
{
	int a;
	int p;
	int d;
	int n;

	a = 0;
	p = 0;
	d = 0;
	n = 0;
	while (a <= 21)
	{
		if (buf[a] == '#')
			d++;
		if (buf[a] == '.')
			p++;
		if (buf[a] == '\n')
			n++;
	a++;
	}
	if (d != 4)
		ERROR;
	if (p != 12)
		ERROR;
	//if ((n != 5) || (n != 4))
	//	ERROR;
}

void		verify_n(char *buf)
{
	int a;

	a = 0;
	while (a <= 3)
	{
		if (buf[a * 5 + 4] != '\n')
			ERROR;
		a++;
	}
}

void		verify_link(char *buf)
{
  int n;
  int j;

  n = 0;
  j = 0;

  while (n < 20)
	{
		if (buf[n] == '#')
		  {
			if (buf[n + 5] == '#')
			  j++;
			if (buf[n - 5] == '#')
			  j++;
			if (buf[n + 1] == '#')
			  j++;
			if (buf[n - 1] == '#')
			  j++;
		  }	
		n++;
	}
	if (j < 6)
		ERROR;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_dlist	*list;

	if (argc != 2)
		ERROR;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ERROR;
	list = get_pieces(fd);
	print_list (list);


	return (0);
}
