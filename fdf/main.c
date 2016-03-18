/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 01:58:15 by yismail           #+#    #+#             */
/*   Updated: 2016/03/18 04:33:46 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (int argc, char **argv)
{
	t_list *list;
	t_list **first;
	void *content;

	content = NULL;
	first = NULL;
	list = NULL;
	list = ft_lstnew(content, sizeof(content));
	*first = list;
	ft_parsing (argc, argv, &list);
}
