/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:06:38 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 18:06:53 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int main (void)
{
    char dest[9] = "bonjour";
    char src[50] = "aueeeeeeerevoir";
    ft_strcpy (dest, src);

    printf ("%s", dest);

}
