/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:55:01 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:20:40 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include		"libft.h"

static char		*ft_itoa_rec(int n, char *s, int *i)
{
	if (n < 0)
	{
		s[*i] = '-';
		*i = *i + 1;
		return (ft_itoa_rec(-n, s, i));
	}
	else if (n >= 10)
	{
		ft_itoa_rec(n / 10, s, i);
		*i = *i + 1;
		return (ft_itoa_rec(n % 10, s, i));
	}
	else
	{
		s[*i] = n + '0';
		return (s);
	}
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 0;
	if ((res = ft_memalloc(20)) == NULL)
	{
		return (NULL);
	}
	return (ft_itoa_rec(n, res, &i));
}
