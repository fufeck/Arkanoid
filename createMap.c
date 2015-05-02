#include "Arkanoid.h"

bool			addBloc(t_draw *arka, eBloc type)
{

}

bool			rmBloc(t_draw *arka, eBloc type)
{
	
}

t_draw			createEnv(const char **map)
{
	t_draw		*arka;
	int 		y;
	int 		x;

	if ((arka = ft_memalloc(sizeof(*arka))) == NULL)
		return (NULL);
	y = 0;
	while (y < Y_MAP)
	{
		x = 0;
		while (x < X_MAP)
		{
			if (map[y][x] != EMPTY)
			{
				if (addBloc(arka, map[y][x]) == false)
					return NULL;
			}
			x++;
		}
		y++;
	}
	return (arka);
}

t_draw			createMap(char fileLvl)
{
	int 		i;
	int 		fd;
	char		*line;
	char		*map[Y_MAP];

	i = 0;
	if ((fd = open(fileLvl, O_RDONLY)) <= 0)
	{
		write(2, "ERROR : file lvl do not exist", ft_strlen("ERROR : file lvl do not exist"));
		return (NULL);
	}
	while (i < Y_MAP)
	{
		line = NULL;
		if (get_next_line(fd, &line) <= 0)
			return (NULL);
		map[i] = line;
		i++;
	}
	return (createEnv(map));
}