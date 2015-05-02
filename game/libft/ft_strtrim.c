/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:30:34 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/22 18:41:09 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char		*ft_strtrim(char const *s)
{
	int		a;
	int		b;

	a = 0;
	b = ft_strlen(s) - 1;
	while (s[a] != '\0' && (s[a] == ' ' || s[a] == '\n' || s[a] == '\t'))
		a++;
	while (b >= 0 && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b--;
	return (ft_strndup(&s[a], b - a + 1));
}
