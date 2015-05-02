/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:06:09 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/22 18:40:14 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<string.h>
#include	"libft.h"

char		*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	if ((s2 = malloc(sizeof(*s1) * (n + 1))) == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0' && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
