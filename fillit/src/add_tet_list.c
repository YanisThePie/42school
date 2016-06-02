/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tet_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:00:36 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 14:31:29 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*add_tet_list(t_tet *tet)
{
	while (tet && tet->next)
		tet = tet->next;
	if (!(tet->next = tet_new(tet->ch + 1)))
		return (NULL);
	return (tet->next);
}
