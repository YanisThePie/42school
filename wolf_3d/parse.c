/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 00:04:42 by yismail           #+#    #+#             */
/*   Updated: 2016/07/26 09:46:20 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void    fill_list(int coord_x, int coord_y, char *val)
{
    long int    val_int;
    t_stru      *content;

    content = (t_stru*)malloc(sizeof(t_stru));
    content->coord_x = coord_x;
    content->coord_y = coord_y;
    val_int = ft_atoi(val);
    if (val_int <= (-2147483648) || val_int >= (2147483647))
        exit(EXIT_FAILURE);
    content->val_int = (int)val_int;
    (*list)->content = (void*)content;
}

void    range_this_shit(t_list **list, int x, int y, char *val)
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
    fill_list(x, y, val, &new);
}

void    ft_split(char *line, int y, t_env *env)
{
    char    **line_spl;
    int     x;

    line_spl = ft_strsplit(line, ' ');
    x = 0;
    while (line_spl[x] != NULL)
    {
        range_this_shit(list, x, y, line_spl[x]);
        x++;
    }
	env->frm.sizemap_x = x;
    freetab(line_spl);
}*/

char *no_space(char *str)
{
	int i;
	int j;
	size_t len;
	char *str2;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * len + 1);
	ft_bzero(str2, len + 1);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		str2[j] = str[i];
		i++;
		j++;
	}
	return(str2);
}

int     check_entry(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '-')
            i++;
        if ((line[i] < 48 && line[i] > 57) && (line[i] != ' ') &&
			(line[i] != '\0' && line[i] != '\n'))
            exit(EXIT_FAILURE);
        i++;
    }
    return (0);
}

int     ft_parsing(int argc, char **argv, t_env *env)
{
    char    *line;
    int     fd;
    int     ret;
    int     coord_y;

	(void)argv;
	(void)argc;
    if (argc != 2)
	  exit(EXIT_FAILURE);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	exit(EXIT_FAILURE);
    coord_y = 0;
    while ((ret = (get_next_line(fd, &line)) > 0))
    {
        check_entry(line);
		env->worldMap[coord_y] = no_space(line);
		env->frm.sizemap_x = ft_strlen(env->worldMap[coord_y]);
        coord_y++;
        free(line);
    }
	env->frm.sizemap_y = coord_y;
    if (ret < 0)
        return (-1);
    return (0);
}
