/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:24:40 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/19 17:04:15 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<string.h>
#include			"libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if ((unsigned char)(c) == tmp2[i])
		{
			return ((void *)(dest + i + 1));
		}
		i++;
	}
	return (NULL);
}
