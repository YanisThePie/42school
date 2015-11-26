/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:27:55 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 20:28:47 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char dest[9] = "bonjour";
    char src[50] = "aur";
    ft_strncpy (dest, src, 5);

    printf ("%s", dest);

}
