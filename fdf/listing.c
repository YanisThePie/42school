/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:13:47 by yismail           #+#    #+#             */
/*   Updated: 2016/04/11 23:48:15 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_list(int coord_x, int coord_y, char *coord_z, t_list **list)
{
	int			height;
	structure	*content;

	content = (structure*)malloc(sizeof(structure));
	content->coord_x = coord_x;
	content->coord_y = coord_y;
	height = ft_atoi(coord_z);
	content->height = height;
	(*list)->content = (void*)content;
}

void	range_this_shit(t_list **list, int x, int y, char *z)
{
	t_list *new;
	t_list *temp;

	temp = *list;
	new = (t_list*)malloc(sizeof(t_list));
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	fill_list(x, y, z, &new);
}

void	ft_split(char *line, int y, t_list **list)
{
	char	**line_spl;
	int		x;

	line_spl = ft_strsplit(line, ' ');
	x = 0;
	while (line_spl[x] != NULL)
	{
		range_this_shit(list, x, y, line_spl[x]);
		x++;
	}
	freetab(line_spl);
}

int		ft_parsing(int argc, char **argv, t_list **list)
{
	char	*line;
	int		fd;
	int		ret;
	int		coord_y;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	coord_y = 0;
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		//ici gestion d'erreur si pas un nombre
		ft_split(line, coord_y, list);
		coord_y++;
		free(line);
	}
	if (ret < 0)
		return (-1);
// gerer les valeurs d'int trop hautes et les negatifs dansune fonction d'erreur.
	return (0);
}
