/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:07 by yismail           #+#    #+#             */
/*   Updated: 2016/06/23 18:28:02 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void l_option(char *dotslash)
{
	struct stat buf;
    struct s_toprint l_option;

    ft_bzero(&l_option, sizeof(struct s_toprint));
    lstat(dotslash, &buf);
    l_option.perm = ft_perm(buf);
    ft_infos(&buf, dotslash, &l_option);
    ft_print_loption(l_option);
}
