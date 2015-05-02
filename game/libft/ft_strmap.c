/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:13:04 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/20 17:44:58 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<string.h>
#include		"libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*ret;
	int			i;

	i = 0;
	if ((ret = ft_memalloc(ft_strlen(s) + 1)) == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
