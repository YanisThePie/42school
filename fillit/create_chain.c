/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2016/01/02 22:00:33 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "fillit.h"

int  print_tab (char **tab)
{
	int i;

	i = 0;
	while (i < 4)
		printf("%s", tab[i++]);
	return (0);
}

t_dlist *ft_dlstnew(void const *content, size_t content_size)
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
		new->content = malloc(content_size);
		if (new->content == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	return(new);
}

void create_list (char **tab)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist **alst;

	//char    tab[10][5];
	//char **tab;
	//tab = malloc(sizeof(char *) * 10);
	//while (i < 5)
	//  tab[i] = malloc(sizeof(char) * 5);

	alst = (t_dlist **)malloc(sizeof(t_dlist *));
	new = NULL;
	new = ft_dlstnew(tab, (sizeof(char) * 21));
	new->content = tab;
	new->next = NULL;
	if(*alst == NULL)
		*alst = new;
	temp = *alst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	print_tab ((char**)new->content);
}
int create_tab(char *piece)
{
	char **tab;
	int lin;
	int col;
	int i;
	static char e = 'A';

	i = 0;
	lin = 0;
	col = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 5)))
		return (0);
	while (col < 5)
	{
		if (!(tab[col] = (char *)malloc(sizeof(char) * 5)))
			return (0);
		col++;
	}
	while (lin < 4)
	{
		col = 0;
		while (col < 5)
		{
			if (piece[i] == '#')
				piece[i] = e;
			tab[lin][col] = piece[i];
			col++;
			i++;
		}
		i++;
		lin++;
	}
	create_list(tab);
	e++;
	return (0);
}

static int create_tab_bis(char *piece, char e)
{
	char **tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	//tab[][];
	tab = (char **)malloc(sizeof(char *) * 5);
	//tab[5][];
	j = 0;
	while (piece[j])
	{
		if (j % 5 == 0)
		{
			k = 0;
			//tab[i][];
			tab[i] = ft_strsub(piece, j, 5); //Alloue et copie les 5 charactere d'une ligne
			//tab[i][5];
			while (k < 5) //regarde les 5 charactere copiés pour remplacer le # par sa MAJUSCULE
			{
				if (tab[i][k] == '#')
					tab[i][k] = e;
				k++;
			}
			printf("%s", tab[i]);
			i++;
		}
		j++;
	}
	return (0);
}

void take (char *buf)
{
	int i;
	int j;
	char *tmp;
	int n;

	i = 0;
	j = 0;
	n = 0;
	tmp = malloc(sizeof(char) * (21 + 1));
	/* while (buf[j] != '\0')
	   {
	   i++;
	   j++;
	   if (buf[j] == '\n' && buf[j + 1] == '\n')
	   {
	   tmp = ft_strsub(buf, (j - i), (i + 2));
	   create_tab (tmp);
	   tmp = NULL;
	   i = 0;
	   j = j + 2;
	   }
	   }*/
	while (buf[j])
	{
		if (buf[j] && j % 21 == 0)
		{
			tmp = ft_strncpy(tmp, buf + j, 21);
			tmp[21] = '\0';
			create_tab_bis(tmp, n + 65);
			//ft_dlstnew();
			n++;
		}
		j += 21;
	}
}

int main (void)
{
	char *str;

	str = ft_strdup("...#\n..#.\n..#.\n...#\n\n..#.\n...#\n..#.\n..#.\n\n.#..\n#...\n.#..\n.#..\n\n..#.\n.#..\n.#..\n#...\n\n");
	ft_putnbr(ft_strlen(str));
	take (str);
	return (0);
}
