/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:07:55 by ftaffore          #+#    #+#             */
/*   Updated: 2015/05/02 13:07:57 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

#include <GLFW/glfw3.h>

# define	MAP_X		15
# define	MAP_Y		10
# define	MAP_YY		20
# define	BLOC_X		40
# define	BLOC_Y		20
# define	RAQUET_X	80
# define	RAQUET_Y	20
# define	BALL_R		10
# define	VEC_R		5

enum eBlock
{
	EMPTY,
	STANDART,
	SOLID,
	INDESTRUCTIBLE	
};

typedef struct			s_img
{
	GLuint				nb[10];
	GLuint				ball;
}						t_img;

typedef struct 			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct			s_bloc
{
	int					type;
	t_pos				pos;
	struct s_bloc		*next;
}						t_bloc;

typedef struct			s_draw
{
	int					end;
	unsigned int		score;
	struct s_bloc		*blocs;
	t_img				img;
	t_pos				ball;
	t_pos				vecBall;
	t_pos				raquet;
}						t_draw;

void					rm_bloc(t_draw *arka, double y, double x);
int						add_bloc(t_draw *arka, int type, double y, double x);
t_draw					*parse_lvl(char *str);
void					refresh_game(t_draw *arka);
void                    draw(GLFWwindow* window, t_draw *arka);


#endif
