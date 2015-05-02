/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:33:09 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:36:24 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if ((ret = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ret = ft_strcat(ret, s1);
	ret = ft_strcat(ret, s2);
	return (ret);
}
