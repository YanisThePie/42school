/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:07 by yismail           #+#    #+#             */
/*   Updated: 2016/06/27 07:00:47 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void simple_option (char *d_name)
{
	ft_putendl (d_name);
}

int R_option(char *dotslash, struct stat *buf, struct s_env env)
{
	lstat(dotslash, buf);
	if (S_ISDIR(buf->st_mode))
	{
		env.dir = opendir (dotslash);
		read_the_path(ft_strjoin(dotslash, "/"), 'R', &env); // change option dynamically
	}
    if (S_ISREG(buf->st_mode))
        ft_putendl (env.pdirent->d_name);
	return (0);
}

void l_option(char *dotslash, char *d_name, struct stat *buf)
{
	//struct stat buf;
    struct s_toprint l_option;

    ft_bzero(&l_option, sizeof(struct s_toprint));
	l_option.name = d_name;
    lstat(dotslash, buf);
    ft_perm(buf, &l_option);
    ft_infos(buf, &l_option);
    ft_print_loption(l_option);
}

int choose_opt(char *dotslash, char option, struct s_env env)
{
	struct stat buf;

    if (option == 'l')
        l_option(dotslash, env.pdirent->d_name, &buf);
    if (option == 's')
        simple_option(env.pdirent->d_name);
	if (option == 'R')
		return(R_option(dotslash, &buf, env));
	return(0);
}
