/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2016/01/06 17:59:50 by yismail          ###   ########.fr       */
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
char  **create_tab_bis(char *piece, char e)
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
	//create_list (tab);
	return (tab);
}
char **take (char *buf, char alpha)
{
	int i;
	int j;
	char *tmp;
	static int n;
	char **tab;

	i = 0;
	j = 0;
	n = 0;
	tmp = malloc(sizeof(char) * (21 + 1));
	tmp = ft_strcpy (tmp, buf);
	tmp[20] = '\0';
	tab = create_tab_bis(tmp, alpha);
	n++;
	return (tab);
}

char ** main_creation (char *buffer, char alpha)
{
	char **tableau;
	tableau = take (buffer, alpha);
	
	
	return (tableau);
}
