/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:32 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:38:21 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char		*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if ((ret = (char *)malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
