/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabet_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:24:47 by yismail           #+#    #+#             */
/*   Updated: 2016/01/06 17:15:51 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


typedef struct	s_list
{
	char			content;
	size_t			content_size;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int  print_list (t_list *lst)
{
    while (lst != NULL)
    {
        printf("%c", lst->content);
        lst = lst->next;
    }

    return (0);
}

t_list * addletter(char alpha)
{
	t_list *lst;

	lst = (t_list*)malloc (sizeof(t_list));
	lst->content = alpha;
    lst->content_size = sizeof(alpha);
	lst->next = NULL;
	return (lst);
}
int main (void)
{
	char	alpha;
	t_list *lst;
	t_list *temp;
	
	alpha = 'a';
	lst = NULL;
	lst = addletter(alpha);
	alpha++;
	while (alpha <= 'z')
	{	
		temp = lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = addletter (alpha);
		alpha++;
	}
	print_list (lst);

	return (0);
}
