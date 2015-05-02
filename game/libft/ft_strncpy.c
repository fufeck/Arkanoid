/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:12:20 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:15:03 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src != NULL)
	{
		while (i <= ft_strlen(src) && i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
