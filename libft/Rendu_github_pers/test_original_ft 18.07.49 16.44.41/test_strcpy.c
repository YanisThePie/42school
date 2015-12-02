/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:30:22 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 17:59:33 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char dest[9] = "bonjour";
	char src[50] = "audfdffdfdfrevoir";
	strcpy (dest, src);

	printf ("%s", dest);

}
