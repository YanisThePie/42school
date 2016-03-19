/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:13:47 by yismail           #+#    #+#             */
/*   Updated: 2016/03/18 04:39:43 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void ft_clean_exit(void *)
{
	
}
*/
void fill_list(char *height_char, int coord_x, int coord_y, t_list **list)
{
	int			height;
	structure	*content;

	content = (structure*)malloc(sizeof(structure));
	content->coord_x = coord_x;
	content->coord_y = coord_y;
	height = ft_atoi (height_char);
	content->height = height;
	(*list) -> content = (void*)content;
}

void ft_split (char *line, int coord_y, t_list **list)
{
	char    **line_spl;
	t_list *new;
	int		i;


	new = (t_list*)malloc(sizeof(t_list));
	line_spl = ft_strsplit(line, ' ');
	i = 0;
	while (line_spl)
	{	
		fill_list(line_spl[i], i, coord_y, list);
		ft_lstadd(list, new);
		(*list) = (*list)->next;
		i++;
	}
}

int ft_parsing (int argc, char **argv, t_list **list)
{
	char	*line;
	int		fd;
	int		ret;
	int		coord_y;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	coord_y = 0;
	while((ret = (get_next_line(fd, &line)) > 0))
	{
		// ici gestion d'erreur si pas un nombre
		ft_split(line, coord_y, list);
		coord_y++;
	}
	if (ret < 0)
		return (-1);
// gerer les valeurs d'int trop hautes et les negatifs dansune fonction d'erreur.
	return(0);
}

