/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:01:08 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/18 22:33:15 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	"libft.h"

void		ft_deltab(char **s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != NULL)
		{
			free(s[i]);
			s[i] = NULL;
			i++;
		}
		free(s[i]);
		s[i] = NULL;
		free(s);
		s = NULL;
	}
}
