/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2016/01/03 22:18:01 by yismail          ###   ########.fr       */
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
	{	
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
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
	
	printf("%d\n", 1);
	alst = (t_dlist **)malloc(sizeof(t_dlist *));
	printf("%d\n", 2);
	new = NULL;
	new = ft_dlstnew(tab, (sizeof(char) * 20));
	printf("%d\n", 3);
	new->content = tab;
	//new->next = NULL;
	printf("%d\n", 4);
	if(*alst == NULL)
	{	
		*alst = new;
	}
	printf("%d\n", 5);
	temp = new;
	//while (temp->next != NULL)
		//	printf ("yo\n");
		//temp = temp -> next;
		//}
		//printf("%d\n", 6);
		//temp ->next = new; 
		//printf("%d\n", 7);
	temp = *alst;
	print_tab ((char**)new->content);
	//print_tab((char**)temp->next);



//	prev->next = maillon
}
void create_tab_bis(char *piece, char e)
{
	char **tab;
	int		i;

	i = 0;
	while (i < 20)
	{
		if (piece[i] == '#')
			piece[i] = e;
		i++;
	}
	i = 0;
	tab = ft_strsplit (piece, '\n');
	create_list (tab);
}
void take (char *buf, char alpha)
{
	int i;
	int j;
	char *tmp;
	static int n;

	i = 0;
	j = 0;
	n = 0;
	tmp = malloc(sizeof(char) * (21 + 1));
	tmp = ft_strcpy (tmp, buf);
	tmp[20] = '\0';
	create_tab_bis(tmp, alpha);
	n++;
}

int main_creation (char *buffer, char alpha)
{
	take (buffer, alpha);
	return (0);
}
