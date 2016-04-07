/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 01:58:15 by yismail           #+#    #+#             */
/*   Updated: 2016/04/07 00:33:04 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_list	*next;
	t_list	*first;
	void	*content;

	content = NULL;
	first = NULL;
	list = NULL;
	ft_parsing(argc, argv, &list);
	first = list;
	ft_window(first);
	while (first != NULL)
	{
		next = first->next;
		free(first->content);
		free(first);
		first = next;
	}
	return (0);
}
