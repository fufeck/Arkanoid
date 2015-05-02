/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:47:27 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:35:13 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		tmp;

	if ((tmp = ft_strncmp(s1, s2, n)) == 0)
		return (1);
	return (0);
}
