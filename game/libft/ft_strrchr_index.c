/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:02:10 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/27 16:48:36 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int			ft_strrchr_index(const char *s, int c)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		i = ft_strlen(s);
		while (i >= 0 && s[i] != (char)c)
			i++;
	}
	return (i);
}
