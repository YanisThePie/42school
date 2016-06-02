/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:54:19 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 14:31:50 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*tet_new(char ch)
{
	t_tet	*new;

	if (!(new = (t_tet*)malloc(sizeof(*new))))
		return (NULL);
	new->ch = ch;
	new->next = NULL;
	return (new);
}
