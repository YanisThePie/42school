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
		//ft_putchar('\n');
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
	square = (char**)malloc (sizeof(char*) * (size * size)+ 1);
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

int place_others_tetri(char ***pointed_square, int line_in_square, int col_in_square, char **tetri, int tmp_line_tetri, int tmp_col_tetri, int n, int size)
{
	int line_tetri;
	int col_tetri;
	char **square;

	square = *pointed_square;
	line_tetri = tmp_line_tetri;
	col_tetri = tmp_col_tetri + 1;
	while (tetri[line_tetri][col_tetri] != '#' && line_tetri < 4)
	{
		while (tetri[line_tetri][col_tetri] != '#' && col_tetri < 4)
		{
			col_tetri++;
		}
		if (col_tetri == 4 && line_tetri < 4)
		{
			line_tetri++;
			col_tetri = 0;
		}
	}
	if (tetri[line_tetri][col_tetri] == '#')
	{
		line_in_square = line_in_square + (line_tetri - tmp_line_tetri);
		col_in_square = col_in_square + (col_tetri - tmp_col_tetri);
		//ft_putnbr(line_in_square);
		//ft_putchar('\n');
		//ft_putnbr(col_in_square);
		//ft_putchar('\n');
		
		if (line_in_square < size && col_in_square < size)
		{
			square[line_in_square][col_in_square] = '#';
			n--;
		}
	}
	tmp_line_tetri = line_tetri;
	tmp_col_tetri = col_tetri;
	if (n > 0)
	{
		if (line_in_square >= size || col_in_square >= size)
			return(0);
		else
			return(place_others_tetri(&square, line_in_square, col_in_square, tetri, tmp_line_tetri, tmp_col_tetri, n, size));
	}
	if (n == 0)
		return (1);
	return (0);
}
int place_first_tetri_diese(char ***pointed_square, int line_in_square, int col_in_square, char **tetri, int line_tetri, int col_tetri, int size)
{
	int tmp_line_tetri;
	int tmp_col_tetri;
	char **square;

	square = *pointed_square;
	while (tetri[line_tetri][col_tetri] == '.' && tetri[line_tetri][col_tetri] != '\n'  && col_tetri < 4)
	{
		col_tetri++;
	}
	if (tetri[line_tetri][col_tetri] == '#')
	{
		tmp_line_tetri = line_tetri;
		tmp_col_tetri = col_tetri;
		square[line_in_square][col_in_square] = tetri[line_tetri][col_tetri];
		if((place_others_tetri(&square, line_in_square, col_in_square, tetri, tmp_line_tetri, tmp_col_tetri, 3, size)) == 1)
			return(1);
		else 
		return(0);
			
	}
	if (col_tetri == 4 && tetri[line_tetri][col_tetri] != '#')
	{
		return(place_first_tetri_diese(&square, line_in_square, col_in_square, tetri, line_tetri+1, 0, size));
	}
	return(0);
}
int is_right (char **square, int lin, int col,int size, int n, t_dlist *list)
{
	if (n > 0 && square[lin][col] == '\0')
		return (0);
	if(square[lin][col] == '.' && (col < size))
	{
		if((place_first_tetri_diese(&square, lin, col,  list->content, 0,0, size) == 1))
		{
			return (1);
		}
		else
			return (is_right(square, lin, col+1, size, n, list));
	}
	
		if (col == size && lin < size)
			return (is_right(square, lin + 1, 0, size, n, list));
		//if (col == size && lin == size && list->next != NULL)
		//{
		//list = list->next;
		//isright(square, 0,
		//}
		return (0);
}

int list_recursive(t_dlist *list, t_dlist *first, char **square, int size)
{
	int result;

	result = 0;
	result = result + (is_right(square, 0, 0, size, 4, list));

	if (result == 0 && result -> next != NULL)
	{
		list = list->next;
		list_recursive(list, first, square, size);
	}
	if (result == 1)
		alpha_tmp = list->alpha;
	if (list == NULL && result != result_to_have)
	{
		list = first;
		while (list-> alpha != alpha_tmp);
		{
			if (place_in_square(list) == 1)
				list = list->next;
		}
		if
	}
}
int place_in_square (t_dlist *list)
{
	char **square;
	static t_dlist *first;
	static int size;
	int result;

	first = list;
	size = 2;
	square = malloc_square(size);
	result = list_recursive(list, first, square, size);
	if (result = 0);
	{
		size = size + 1;
		list = first;
		place_in_square(list, size + 1);
	}
}
return (0);
// partie a revoir, au niveau de la recursivite des listes.
}
