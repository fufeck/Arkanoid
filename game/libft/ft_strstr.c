/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:13:16 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:20:33 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	<string.h>
#include	"libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	if (s1 != NULL)
	{
		while (ft_strlen(s1) - i >= ft_strlen(s2))
		{
			if (ft_strncmp(((char *)s1 + i), s2, ft_strlen(s2)) == 0)
			{
				return (((char *)s1 + i));
			}
			i++;
		}
	}
	return (NULL);
}
