


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_yanis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:46:54 by yismail           #+#    #+#             */
/*   Updated: 2016/01/11 08:48:03 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_it (char **tab)
{
	int i;

	i = 0;
	ft_putstr (tab[i]);
	i++;
	ft_putstr (tab[i]);
	i++;
	ft_putstr (tab[i]);
}

char **malloc_square (size_t size)
{
	char **square;
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	square = (char**)malloc (sizeof(char*) * (size * size) + 1);
	while (i <= size)
	{	
		square[i] = (char*)malloc(sizeof(char) * (size) + 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = '\n';
		i++;
	}
	return (square);		
}
/*
char **place_piece(char **square, t_dlist *list)
{
	int i;
	int j;
	int lin;
	int col;

	i = 0;
	j = 0;
	lin = 0;
	col = 0;
	while (list->content[i][j] != '\0')
	{
		ft_putnbr (i);
		ft_putchar ('\n');
		j = 0;
		while(list->content[i][j] != '\n')
		{
			ft_putnbr (j);
			ft_putchar ('\n');
			if (list->content[i][j] == '#')
			{
				lin = 0;
				while (square[lin][col] != '\0')
				{
					ft_putnbr (lin);
					ft_putchar ('\n');
					col = 0;
					while (square[lin][col] != '\n')
					{
						ft_putnbr (col);
						ft_putchar ('\n');
						if (square [lin][col] == '.')
							square[lin][col] = list->content[i][j];
						col++;
					}
					lin++;
				}
			}
			j++;
		}
		i++;
	}
	return (square);
*/
int is_right (char **square, int lin, int col, int size)
{
	ft_putnbr (col);
	ft_putchar('C');
	ft_putchar ('\n');
	ft_putnbr(lin);
	ft_putchar('L');
	ft_putchar ('\n');
	if (square[lin][col] == '\0')
		return (1);
	//if (col == size)
	//{
		//ft_putnbr(lin);
		//ft_putchar('L');
		//ft_putchar ('\n');
	//	lin = lin + 1;
	//	col = -1;
	//}
	if(square[lin][col] == '.' && (col < size))
		return (is_right(square, lin, col+1, size));
	else
	{
		if (lin < size)
		{
			col = -1;
			return (is_right(square, lin + 1, col + 1, size));
		}
	}
	return (0);
}

int place_in_square (t_dlist *list)
{
	char **square;
	int size;
	int result;

	list = NULL;//a retirer
	size = 2;
	square = malloc_square(size);
	result = is_right(square, 0, 0, size);
	ft_putnbr (result);
	print_it (square);
	return (0);
}
