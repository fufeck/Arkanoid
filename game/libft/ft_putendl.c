/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:30:57 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:27:12 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"libft.h"

void		ft_putendl(char const *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}
