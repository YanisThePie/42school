/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2015/12/31 05:32:47 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"

/*
int print_tab (char **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
        while (j < 4)
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf ("\n");
	return (0);
}
*/

void create_list (char **tab, t_list **alst)
{
	t_list *new;
		new = ft_lstnew(tab, (sizeof(char) * 21));
		if(*alst == NULL)
			*alst = new;
		new->next = NULL;
}
int create_tab(char *piece)
{
	char **tab;
	t_list **alst;
	int lin;
	int col;
	int i;
	
	i = 0;
	lin = 0;
	col = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 16)))
		return (0);
	while (col < 4)
	{
		if (!(tab[col] = (char *)malloc(sizeof(char) * 1)))
			return (0);
		col++;
	}
	while (lin < 4)
	{
		col = 0;
		while (col < 4)
		{
			tab[lin][col] = piece[i];
			col++;
			i++;
		}
		i++;
		lin++;
	}
	create_list(tab, alst);
//	print_tab (tab);
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
	while (buf[j] != '\0')
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
	}
}
int main (void)
{
	char *str;

	str = ft_strdup("..#.\n..#.\n...#\n...#\n\n..#.\n...#\n..#.\n..#.\n\n.#..\n#...\n.#..\n.#..\n\n");
	take (str);
	return (0);
}
