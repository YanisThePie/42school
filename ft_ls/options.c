/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:07 by yismail           #+#    #+#             */
/*   Updated: 2016/06/26 19:55:05 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void l_option(char *dotslash, char *d_name)
{
	struct stat buf;
    struct s_toprint l_option;

    ft_bzero(&l_option, sizeof(struct s_toprint));
	l_option.name = d_name;
    lstat(dotslash, &buf);
    ft_perm(buf, &l_option);
    ft_infos(&buf, &l_option);
    ft_print_loption(l_option);
}
