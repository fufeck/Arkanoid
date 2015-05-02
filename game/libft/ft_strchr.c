/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:27:02 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:33:33 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<string.h>
#include			"libft.h"

char				*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (i <= ft_strlen(s))
		{
			if (s[i] == (char)c)
			{
				return ((char *)s + i);
			}
			i++;
		}
	}
	return (NULL);
}
