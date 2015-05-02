/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:25:33 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:49:20 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if ((ret = ft_strndup(&s[start], len)) == NULL)
		return (NULL);
	return (ret);
}
