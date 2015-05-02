/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:46:32 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:18:05 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<string.h>
#include			"libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == ((unsigned char)c))
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
