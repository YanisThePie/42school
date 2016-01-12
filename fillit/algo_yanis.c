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
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar ('\n');
		i++;
	}
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

int place_others_tetri(char ***pointed_square, int lin, int col, char **tab, int first_tmp_i, int first_tmp_j, int n)
{
	int i;
	int j;
	char **square;

	//ft_putstr("tmp");
	//ft_putchar('\n');
	//ft_putnbr(first_tmp_i);
	square = *pointed_square;
	i = first_tmp_i;
	j = first_tmp_j + 1;

	//print_it(square);
	//ft_putnbr(j);
	ft_putchar('\n');

		while (tab[i][j] != '#' && i < 4 && j < 4)
		{
			ft_putnbr(j);
			ft_putchar('\n');
			if (j == '\n')
			{
				i++;
				//j = -1;
			}
			j++;
		}
	if (tab[i][j] == '#')
	{
		lin = lin + (i - first_tmp_i);
		col = col + (j - first_tmp_j);
		square[lin][col] = '#';
	}
	first_tmp_i = i;
	first_tmp_j = j;
	n--;
	if (n > 0)
		return(place_others_tetri(&square, lin, col, tab, first_tmp_i, first_tmp_j, n));
	if (n == 0)
		return (1);
	return (0);
}
int place_first_tetri_diese(char ***pointed_square, int lin, int col, char **tab, int i, int j)
{
	int first_tmp_i;
	int first_tmp_j;
	char **square;

	
	square = *pointed_square;
	while (tab[i][j] != '#')
	{
		j++;
	}
	if (tab[i][j] == '#')
	{
		first_tmp_i = i;
		first_tmp_j = j;
		square[lin][col] = tab[i][j];
		if((place_others_tetri(&square, lin, col, tab, first_tmp_i, first_tmp_j, 3)) == 1)
		{

			return(1);
		}
	}
	if (tab[i][j] == '\n')
		return(place_first_tetri_diese(&square, lin, col, tab, i+1, 0));
	return (0);
}

int is_right (char **square, int lin, int col,int size, int n, t_dlist *list)
{
	//print_it(square);
	if (square[lin][col] == '\0' && n == 0)
	{
		return (1);
	}
	//if (col == size)
	//{
	//ft_putnbr(lin);
	//ft_putchar('L');
	//ft_putchar ('\n');
	//	lin = lin + 1;
	//	col = -1;
	//}
	if (n > 0 && square[lin][col] == '\0')
		return (0);
	if(square[lin][col] == '.' && (col < size))
	{
		if((place_first_tetri_diese(&square, lin, col,  list->content, 0,0) == 1))
		{
			//print_it(square);
			return (1);
		}
		return (is_right(square, lin, col+1, size, n, list));
	}
	else
	{
		if (lin < size)
		{
			col = -1;
			return (is_right(square, lin + 1, col + 1, size, n, list));
		}
	}
	return (0);
}

int place_in_square (t_dlist *list)
{
	char **square;
	int size;
	
	size = 2;
	square = malloc_square(size);
	//print_it(square);
	while(is_right(square, 0, 0, size, 4, list) == 0)
	{
		size = size + 1;
		square = malloc_square(size);
	}
	//ft_putnbr (result);
	//print_it (square);
	return (0);
}
