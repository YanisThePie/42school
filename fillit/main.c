/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:14:38 by jaustry           #+#    #+#             */
/*   Updated: 2016/01/11 07:12:43 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  print_list (t_dlist *lst)
{
	int i;
	int j;

    j = 0;
	while (lst !=  NULL && j == 0)
    {
		i = 0;
		while (i < 4)
		{
			ft_putstr (lst->content[i]);
			ft_putchar(lst->alpha);
			ft_putchar('\n');
			i++;
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			j = 1;
    }
//	lst = lst->prev;
	j = 0;
    while (lst != NULL && j == 0)
	{
        i = 0;
        while (i < 4)
        {
            ft_putstr (lst->content[i]);
			ft_putchar(lst->alpha);
            ft_putchar('\n');
            i++;
        }
		if (lst->prev != NULL)
			lst = lst->prev;
		else
			j = 1;
	}
	return (0);
}
/*while (lst->next != NULL)
		lst = lst->next;
	while (lst != NULL)
	{
		i = 0;
		while (i < 4)
		{
			ft_putstr(lst->content[i]);
			ft_putchar(lst->alpha);
			ft_putchar('\n');
			ft_putnbr(i);
			i++;
		}
		lst = lst->prev;
	}
	return (0);
	}*/
t_dlist *ft_dlstnew(char **content, size_t content_size, t_dlist *tmp)
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
      new->content = content;
      new->content_size = content_size;
	  if (tmp)
		  new->prev = tmp;
	  if (new->prev)
	  new->alpha = new->prev->alpha + 1;
    }
    return(new);
}

t_dlist *ft_lstpushback(t_dlist *first, char **tab, t_dlist *prev)
{
	t_dlist			*tmp;

	prev = NULL;//a retirer?
	tmp = NULL;
	if (first == NULL)
	{
		first = ft_dlstnew(tab, sizeof(tab), tmp);
		first->alpha = 'A';
		first->prev = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_dlstnew(tab, sizeof(tab), tmp);
		tmp->next->prev = tmp;
		//if (prev != NULL)
        //{
		//  tmp->next->prev = prev;
        //}
	}
	return (first);
}

# define SIZE_OF_TETRIMINOS     (21 * sizeof(char))
t_dlist		*get_pieces(int fd)
{
	char	buf[21 +1];
	ssize_t	r;
	char	**tab;
	t_dlist	*first;
	static t_dlist *prev;

	first = NULL;
	prev = NULL;
	while ((r = read(fd, buf, 21)))
	{
		buf[r] = '\0';
		verify_piece(buf);
		verify_n(buf);
		verify_link(buf);
		tab = main_creation(buf);
		first = ft_lstpushback (first, tab, prev);
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
	//print_list(list);
	place_in_square (list, 2);


	return (0);
}
