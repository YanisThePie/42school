/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 01:58:15 by yismail           #+#    #+#             */
/*   Updated: 2016/04/02 17:11:39 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_putlist(t_list *elem)
{
    ft_putnbr(((structure *)elem->content)->coord_x);
	ft_putchar(' ');
	ft_putnbr(((structure *)elem->content)->coord_y);
	ft_putchar(' ');
	ft_putnbr(((structure *)elem->content)->height);
	ft_putchar('\n');
}

int main (int argc, char **argv)
{
	t_list *list;
	t_list *first;
	void *content;

	content = NULL;
	first = NULL;
	list = NULL;
	list = ft_lstnew(content, sizeof(structure));
	first = list;
	ft_parsing (argc, argv, &list);
	ft_window(first);
	return (0);
}
