/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:21:54 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:19:57 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t l)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(dst);
	while (src[a] != '\0' && b < l - 1)
	{
		dst[b] = src[a];
		a++;
		b++;
	}
	dst[b] = '\0';
	return (b);
}
