/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:50 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:09:18 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int			ft_atoi_calc(const char *s)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res);
}

int			ft_atoi(const char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while ((s[i] >= '\a' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-')
		return (-ft_atoi_calc(&s[i + 1]));
	else if (s[i] == '+')
		return (ft_atoi_calc(&s[i + 1]));
	else
		return (ft_atoi_calc(&s[i]));
}
