/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:43 by yismail           #+#    #+#             */
/*   Updated: 2016/06/27 10:02:35 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int read_the_path(char *path, char option, struct s_env *env) //une seule var env
{
	int i;

	i = 0;
    while((env->pdirent = readdir(env->dir)) != NULL)
    {
		if (!(env->pdirent->d_name[i] == '.' && option != 'a'))
		{
			env->dotslash = ft_strjoin(path, env->pdirent->d_name);
			if (option != '\0')
				choose_opt(env->dotslash, option, *env);
			else
				choose_opt(NULL, 's' ,*env);
		}
	}
	closedir (env->dir); //probleme closedir -R
	return (0);
}

int how_many_flags (char **argv, struct s_env *env)
{
	int i;
	int j;
	int k;
	char option[99];
	char *path;
	
	i = 1;
	j = 0;
	k = 0;
	ft_bzero(option, sizeof(char) * 99);
	if (argv[i][j] == '-')
	{
		j++;
		while (ft_isalpha(argv[i][j]))
		{	 
			option[k] = argv[i][j];
			k++;
			j++;
		}
		i++;
	}
	if (argv[i] == NULL)
	{
		env->dir = opendir ("./");
		path = "./";
	}
	else if (argv[i] != NULL)
	{
		path = ft_strjoin(argv[i], "/");
		env->dir = opendir(path);
	}
    if (env->dir == NULL)
    {
        perror("");
        return(0);
    }
	k = 0;
	while (option[k] != '\0')
	{
		read_the_path(path, option[k], env);
		k++;
	}
	return(0);
}

int no_arg(struct s_env *env)
{
	env->dir = opendir(".");
    if (env->dir == NULL)
    {
        perror("");
        return(0);
    }
	while((env->pdirent = readdir(env->dir)) != NULL)
		read_the_path ( NULL,'s', env);
	return(0);
}
