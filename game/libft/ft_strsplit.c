/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:32:34 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/12 10:26:13 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>
#include			"libft.h"

static int			ft_split(char const *s, char c, size_t *a, size_t *b)
{
	if (s[*b] == '\0')
		return (0);
	*a = *b;
	while (s[*a] == c)
		*a = *a + 1;
	*b = *a;
	if (s[*b] == '\0')
		return (0);
	while (s[*b] != '\0' && s[*b] != c)
		*b = *b + 1;
	return (1);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	size;
	char			**res;
	size_t			a;
	size_t			b;

	a = 0;
	b = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (ft_split(s, c, &a, &b) == 1)
		size++;
	if ((res = malloc(sizeof(res) * (size + 1))) == NULL)
		return (NULL);
	size = 0;
	a = 0;
	b = 0;
	while (ft_split(s, c, &a, &b) == 1)
	{
		res[size] = ft_strndup(&s[a], b - a);
		size++;
	}
	res[size] = NULL;
	return (res);
}
