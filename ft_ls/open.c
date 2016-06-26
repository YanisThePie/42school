/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:43 by yismail           #+#    #+#             */
/*   Updated: 2016/06/26 19:53:54 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void choose_opt(char *dotslash, char *argv, char *d_name)
{
	if (!strcmp(argv, "-l"))
		l_option(dotslash, d_name);
}
int main (int argc, char **argv)
{
	(void)argc;
	DIR *dir;
	struct dirent *pdirent;
	char *full_path;
	char *dotslash;

	if (argv[2] == NULL)
		dir = opendir(".");
	else
		dir = opendir(argv[2]);
	if (dir == NULL)
	{
		perror("");
		return(0);
	}
	while((pdirent = readdir(dir)) != NULL)
	{
		if (argv[2] != NULL)
		{	
			full_path = ft_strjoin(argv[2], "/");
			dotslash = ft_strjoin(full_path, pdirent->d_name);
			choose_opt(dotslash, argv[1], pdirent->d_name);
		}
		else
			l_option(pdirent->d_name, pdirent->d_name); // no option, listing ls
	}
	closedir (dir);
}
