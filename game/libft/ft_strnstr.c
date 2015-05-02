/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:19:45 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/27 17:57:20 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	if (s1 != NULL && n > 0 && ft_strlen(s1) >= n)
	{
		while (n - i >= ft_strlen(s2))
		{
			if (ft_strncmp(((char *)&s1[i]), s2, ft_strlen(s2)) == 0)
			{
				return ((char *)(&s1[i]));
			}
			i++;
		}
	}
	return (NULL);
}
