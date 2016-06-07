/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usestat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:52:51 by yismail           #+#    #+#             */
/*   Updated: 2016/06/07 16:17:30 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_infos (struct stat buf, char *d_name, struct s_toprint *l_option)
{
    struct passwd *pw;
    struct group *gr;

    pw = getpwuid(buf.st_uid);
    gr = getgrgid(buf.st_gid);
    if (pw != 0)
		l_option->uid = pw->pw_name;
    if (gr != 0)
        l_option->gid = gr->gr_name;
    l_option->time = (ctime(&buf.st_atime) + 3);
    l_option->name = (d_name);
}

void ft_perm (struct stat buf, struct s_toprint *l_option)
{
    char *perm_buffer;

    perm_buffer = malloc(sizeof(char) *10);
    perm_buffer[0] = buf.st_mode & S_IFREG ? '-' : (buf.st_mode & S_IFDIR ? 'd' : '#');
    perm_buffer[1] = buf.st_mode & S_IRUSR ? 'r' : '-';
    perm_buffer[2] = buf.st_mode & S_IWUSR ? 'w' : '-';
    perm_buffer[3] = buf.st_mode & S_IXUSR ? 'x' : '-';
    perm_buffer[4] = buf.st_mode & S_IRGRP ? 'r' : '-';
    perm_buffer[5] = buf.st_mode & S_IWGRP ? 'w' : '-';
    perm_buffer[6] = buf.st_mode & S_IXGRP ? 'x' : '-';
    perm_buffer[7] = buf.st_mode & S_IROTH ? 'r' : '-';
    perm_buffer[8] = buf.st_mode & S_IWOTH ? 'w' : '-';
    perm_buffer[9] = buf.st_mode & S_IXOTH ? 'x' : '-';
    perm_buffer[10] = '\0';
    l_option->perm = perm_buffer;
}

int usestat (char *d_name)
{
    struct stat buf;
	struct s_toprint l_option;

    lstat(d_name, &buf);
    ft_perm(buf, &l_option);
    ft_infos(buf, d_name, &l_option);
    return(0);
}
