/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 00:04:42 by yismail           #+#    #+#             */
/*   Updated: 2016/11/07 11:31:50 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int *ft_table_atoi(char *src, int sizemap)
{
	int *dest;
	int cpt;

	dest = malloc(sizeof(int) * sizemap);
	cpt = 0;
	while (sizemap)
	{
		dest[cpt] = (src[cpt] - 48);
		cpt++;
		sizemap--;
	}

	
	return(dest);
}

int     ft_parsing(int argc, char **argv, t_env *env)
{
    char    *line;
    int     fd;
    int     ret;
    int     coord_y;

	(void)argv;
    if (argc != 2)
	  exit(EXIT_FAILURE);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	exit(EXIT_FAILURE);
    coord_y = 0;
    while ((ret = (get_next_line(fd, &line)) > 0))
    {
        check_entry(line);
		env->worldMapchar[coord_y] = no_space(line);
		env->frm.sizemap_x = ft_strlen(env->worldMapchar[coord_y]);
		env->worldMap[coord_y] = ft_table_atoi(env->worldMapchar[coord_y], env->frm.sizemap_x);
        coord_y++;
        free(line);
    }
	env->frm.sizemap_y = coord_y;
    if (ret < 0)
        return (-1);
    return (0);
}
