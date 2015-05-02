/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:08:04 by ftaffore          #+#    #+#             */
/*   Updated: 2015/05/02 13:08:05 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "arkanoid.h"

int				add_bloc(t_draw *arka, int type, double y, double x)
{
	t_bloc		*new;

	if ((new = ft_memalloc(sizeof(*new))) == NULL)
		return (-1);
	new->type = type;
	new->pos.y = y * BLOC_Y;
	new->pos.x = x * BLOC_X;
	new->next = NULL;
	if (arka->blocs != NULL)
		new->next = arka->blocs;
	arka->blocs = new;
	//printf("%f %f\n", new->pos.y, new->pos.x);

	return (0);
}

static t_draw	*init_draw(void)
{
	t_draw		*arka;

	if ((arka = ft_memalloc(sizeof(*arka))) == NULL)
		return (NULL);
	arka->end = 0;
	arka->score = 0;
	arka->blocs = NULL;
	arka->ball.y = MAP_YY * BLOC_Y - 2 * RAQUET_Y - BALL_R * 2;
	arka->ball.x = MAP_X * BLOC_X / 2;
	arka->vecBall.y = BALL_R / 2;
	arka->vecBall.x = 0;
	arka->raquet.y = MAP_YY * BLOC_Y - 2 * RAQUET_Y;
	arka->raquet.x = MAP_X * BLOC_X / 2 - RAQUET_X / 2;
	return (arka);
}

static t_draw	*create_env(char **map)
{
	t_draw		*arka;
	int			y;
	int			x;

	if ((arka = init_draw()) == NULL)
		return (NULL);
	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (map[y][x] - '0' != EMPTY)
			{
				if (add_bloc(arka, map[y][x] - '0', y, x) < 0)
					return (NULL);
			}
			x++;
		}
		y++;
	}
	return (arka);
}

static t_draw	*create_map(char *file_lvl)
{
	int			i;
	int			fd;
	char		*line;
	char		*map[MAP_Y];

	i = 0;
	if ((fd = open(file_lvl, O_RDONLY)) <= 0)
	{
		write(2, "ERROR : file lvl do not exist\n", 30);
		return (NULL);
	}
	while (i < MAP_Y)
	{
		line = NULL;
		if (get_next_line(fd, &line) <= 0)
			return (NULL);
		map[i] = line;
		i++;
	}
	return (create_env(map));
}

t_draw			*parse_lvl(char *str)
{
	char		file_lvl[14];
	int			lvl;

	ft_bzero(file_lvl, 14);
	lvl = ft_atoi(str);
	if (lvl < 0 || lvl > 10)
	{
		write(2, "ERROR : lvl is not correct\n", 27);
		return (NULL);
	}
	ft_strcat(file_lvl, "levels/level");
	file_lvl[12] = (lvl + '0');
	file_lvl[13] = '\0';
	return (create_map(file_lvl));
}
