/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:29:20 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:20:21 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s != NULL)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			if (s[i] == (char)c)
			{
				return ((char *)s + i);
			}
			i--;
		}
	}
	return (NULL);
}
