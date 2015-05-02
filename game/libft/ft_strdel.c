/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:59:52 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/18 19:27:55 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

void		ft_strdel(char **as)
{
	if (*as != NULL)
	{
		free (*as);
		*as = NULL;
	}
}