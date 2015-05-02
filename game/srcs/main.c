/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:08:10 by ftaffore          #+#    #+#             */
/*   Updated: 2015/05/02 13:08:11 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "arkanoid.h"

static void			setRaquet(t_draw *arka, int dir)
{
	static t_draw   *ptr = NULL;
	
	if (arka != NULL)
		ptr = arka;
	else if (ptr != NULL && arka == NULL)
	{
		if (dir == GLFW_KEY_LEFT)
			ptr->raquet.x = (ptr->raquet.x - 5 > 0) ? (ptr->raquet.x - 5) : (0);
		else
		{
			ptr->raquet.x = ptr->raquet.x + 5;
			if (ptr->raquet.x + RAQUET_X > MAP_X * BLOC_X)
				ptr->raquet.x = MAP_X * BLOC_X - RAQUET_X;
		}
	}
}

static void		error_callback(int error, const char* description)
{
	(void)error;
	write(2, description, ft_strlen(description));
	write(2, "\n", 1);
}

static void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)mods;
	(void)scancode;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT)
		setRaquet(NULL, key);
}


int				mainloop(t_draw *arka)
{
	GLFWwindow  *window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-1);
	window = glfwCreateWindow(MAP_X * BLOC_X, MAP_YY * BLOC_Y, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window) && arka->end == 0)
	{
		refresh_game(arka);
		draw(window, arka);
		usleep(50000);
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}

int				main(int ac, char **av)
{
	t_draw		*arka;

	if (ac == 2)
	{
		if ((arka = parse_lvl(av[1])) == NULL)
			return (1);
		mainloop(arka);
	}
	else
		write(1, "USAGE : ./Arkanoid lvl\n", 23);
	return (0);
}
