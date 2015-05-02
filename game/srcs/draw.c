/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:30:14 by ftaffore          #+#    #+#             */
/*   Updated: 2015/05/02 17:30:15 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "arkanoid.h"

t_color					g_colors[3] = {
	{-0.6f, -0.4f, 0.f},
	{-0.8f, -0.8f, 0.8f},
	{-0.5f, -0.0f, 0.5f}
};

static t_pos            transform_coord(double y, double x)
{
	t_pos				res;

	res.x = (x / (MAP_X * BLOC_X / 2)) - 1;
	res.y = - ((y / (MAP_YY * BLOC_Y / 2)) - 1);
	return (res);
}

static void             draw_blocs(t_draw *arka)
{
	t_bloc				*bloc;
	t_color				c;
	t_pos				p;

	bloc = arka->blocs;
	glBegin(GL_QUADS);
	while (bloc != NULL)
	{
		//printf("%f %f\n", bloc->pos.y, bloc->pos.x);
		c = g_colors[bloc->type - 1];
		glColor3f(c.r, c.g, c.b);

		p = transform_coord(bloc->pos.y, bloc->pos.x);
		glVertex3f(p.x, p.y, 0.f);
		p = transform_coord(bloc->pos.y, bloc->pos.x + BLOC_X);
		glVertex3f(p.x, p.y, 0.f);
		p = transform_coord(bloc->pos.y + BLOC_Y, bloc->pos.x + BLOC_X);
		glVertex3f(p.x, p.y, 0.f);
		p = transform_coord(bloc->pos.y + BLOC_Y, bloc->pos.x);
		glVertex3f(p.x, p.y, 0.f);
		bloc = bloc->next;
	}
	glEnd();
}

static void             draw_raquet(t_draw *arka)
{
	t_pos				raq;
	t_pos				p;

	raq = arka->raquet;
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.0);
	p = transform_coord(raq.y, raq.x);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(raq.y, raq.x + RAQUET_X);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(raq.y + RAQUET_Y, raq.x + RAQUET_X);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(raq.y + RAQUET_Y, raq.x);
	glVertex3f(p.x, p.y, 0.f);
	glEnd();

}

static void             draw_ball(t_draw *arka)
{
	t_pos				ball;
	t_pos				p;

	ball = arka->ball;
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.8, 0.8);
	p = transform_coord(ball.y - BALL_R, ball.x - BALL_R);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(ball.y - BALL_R, ball.x + BALL_R);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(ball.y + BALL_R, ball.x + BALL_R);
	glVertex3f(p.x, p.y, 0.f);
	p = transform_coord(ball.y + BALL_R, ball.x - BALL_R);
	glVertex3f(p.x, p.y, 0.f);
	glEnd();
}

void                      draw(GLFWwindow* window, t_draw *arka)
{
	float               ratio;
	int                 width;
	int                 height;

	glEnable(GL_TEXTURE_2D);
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	glMatrixMode(GL_MODELVIEW);

	draw_blocs(arka);
	draw_raquet(arka);
	draw_ball(arka);

	glfwSwapBuffers(window);
	glfwPollEvents();
}
