/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:18:52 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 20:23:30 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int main (void)
{
    char dest[9] = "bonjour";
    char src[50] = "aur";
    strncpy (dest, src, 5);

    printf ("%s", dest);

}
