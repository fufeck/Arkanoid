/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:38:58 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:17:56 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<string.h>
#include	"libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*dst;
	size_t	i;

	i = 0;
	dst = dest;
	if ((tmp = (char *)(ft_memalloc(n + 1))) == NULL)
	{
		return (NULL);
	}
	tmp = ft_memcpy((void *)tmp, src, n);
	while (i < n)
	{
		dst[i] = tmp[i];
		i++;
	}
	free((void *)tmp);
	return (dest);
}
