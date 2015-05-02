/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:45:53 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/20 16:51:57 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if ((ret = (char *)malloc(size)) == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void*)ret);
}
