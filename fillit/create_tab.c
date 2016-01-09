/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2016/01/09 15:42:22 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "fillit.h"

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
	return (tab);
}
char **take (char *buf, char alpha)
{
	char *tmp;
	char **tab;

	tmp = malloc(sizeof(char) * (21 + 1));
	tmp = ft_strcpy (tmp, buf);
	tmp[20] = '\0';
	tab = create_tab_bis(tmp, alpha);
	return (tab);
}

char ** main_creation (char *buffer, char alpha)
{
	char **tableau;
	tableau = take (buffer, alpha);
	return (tableau);
}
