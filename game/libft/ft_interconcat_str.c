/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interconcat_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:55:37 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/18 17:08:02 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char		*ft_interconcat_str(const char *s1, const char *s2, const char *s3)
{
	char	*new;
	int		j;

	j = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if ((new = (char *)ft_memalloc(j)) == NULL)
		return (NULL);
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	new = ft_strcat(new, s3);
	return (new);
}
