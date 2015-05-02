#ifndef ARKANOID_H
# define ARKANOID_H

# define	MAP_X		15
# define	MAP_Y		5

# define	BLOC_X		40
# define	BLOC_Y		20

# define	RAQUET_X	80
# define	RAQUET_Y	20

# define	BALL_R		10

enum eBlock
{
	STANDART,
	SOLID,
	INDESTRUCTIBLE	
};

typedef struct 		s_pos
{
	unsigned int 	x;
	unsigned int 	y;
};

typedef struct 		s_bloc
{
	eBlock			type;
	t_pos 			pos;
	struct s_bloc	*next;
}					t_bloc;

typedef struct s_draw
{
	struct s_bloc	blocs;
	t_pos			ball;
	t_pos			raquet;
}					t_draw;

#endif