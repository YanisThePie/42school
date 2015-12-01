/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:59:46 by yismail           #+#    #+#             */
/*   Updated: 2015/11/29 17:00:14 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main (void)
{
    size_t i;
    size_t j;
    char dest[50] = "bonjouresasas";
    char src[50] = "monsieuresasas";
    char dest2[50] = "bonjouresasas";
    char src2[50] = "monsieuresasas";

    i = ft_strlcat (dest, src, 2);
    printf ("%zu\n", i);
    printf("%s\n", dest);
    j = strlcat (dest2, src2, 2);
    printf ("%zu\n", j);
    printf("%s\n", dest2);
}
