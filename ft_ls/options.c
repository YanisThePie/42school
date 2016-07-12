/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:07 by yismail           #+#    #+#             */
/*   Updated: 2016/07/12 02:03:27 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int R_option(char *dotslash, struct stat *buf, struct s_env env)
{
	lstat(dotslash, buf);
	if (S_ISREG(buf->st_mode))
		ft_putchar(9);
	if (S_ISDIR(buf->st_mode))
	{
		if (access(dotslash, X_OK) == -1)
		{	
			ft_putendl("   ft_ls: Permission denied");
			return(-1);
		}
	}
	print_simple_option(env.pdirent->d_name);
	if((env.dir = opendir (dotslash)))
		//return(0);
		read_the_path(ft_strjoin(dotslash, "/"), "R", env); // change option dynamically
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
	//ft_infos(buf, &l_option);
	ft_putstr(l_option.perm);
    ft_infos(buf, &l_option);
	//ft_putstr("EH");
	//ft_putnstr(l_option.perm);
    ft_putnstr(l_option.links);
    ft_putnstr(l_option.uid);
    ft_putnstr(l_option.gid);
    ft_putnstr (l_option.size);
    ft_putstrlen(l_option.time, 12);
    ft_putchar(' ');
    ft_putendl(l_option.name);
}

void s_option(char *d_name, struct stat *buf)
{
	struct s_toprint s_option;

	s_option.name = d_name;
	ft_infos(buf, &s_option);
	ft_putstr(s_option.size);
    ft_putchar(' ');
}

//void t_option ()

int choose_opt(char *dotslash, char *option, struct s_env env)
{
	struct stat buf;

	if ((strchr(option, 's')))
		s_option(env.pdirent->d_name, &buf);
	if ((strchr(option, 'l')))
		l_option(dotslash, env.pdirent->d_name, &buf);

	/*if (option == 's')
			s_option(env.pdirent->d_name, &buf);
		if (option == 'R')
			return(R_option(dotslash, &buf, env));
		if (option == 'a')
			print_simple_option(env.pdirent->d_name);
		k++;
	}
	*/
	return(0);
}
	
