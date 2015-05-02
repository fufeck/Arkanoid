/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:30:35 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:21:20 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int					ft_isalpha(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
	{
		return (1);
	}
	return (0);
}