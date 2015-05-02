/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:15:51 by ftaffore          #+#    #+#             */
/*   Updated: 2015/05/02 13:15:51 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "arkanoid.h"

void			rm_bloc(t_draw *arka, double y, double x)
{
	t_bloc		*ptr1;
	t_bloc		*ptr2;

	ptr1 = arka->blocs;
	ptr2 = ptr1;
	while (ptr1 != NULL && ptr1->pos.y != y && ptr1->pos.x != x)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	if (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1 != arka->blocs)
			ptr2->next = ptr1->next;
		free(ptr1);
		ptr1 = NULL;
		if (ptr1 == arka->blocs)
			arka->blocs = NULL;
	}
}

static void		check_colision_window(t_draw *arka)
{
	if (arka->ball.x - BALL_R < 0)
		arka->vecBall.x = -arka->vecBall.x;
	else if (arka->ball.x + BALL_R > BLOC_X * MAP_X)
		arka->vecBall.x = -arka->vecBall.x;
	else if (arka->ball.y - BALL_R < 0)
		arka->vecBall.y = -arka->vecBall.y;
	else if (arka->ball.y > BLOC_Y * MAP_YY)
		arka->end = 1;
}

static void		check_colision_raquet(t_draw *arka)
{
	t_pos		raquet;
	t_pos		ball;
	double		ratiox;

	raquet = arka->raquet;
	ball = arka->ball;
	ratiox = (ball.x - (raquet.x + RAQUET_X / 2)) / (RAQUET_X / 2 / BALL_R);
	if (ball.x + BALL_R >= raquet.x && ball.x - BALL_R <= raquet.x + BLOC_X && \
		ball.y + BALL_R >= raquet.y && ball.y - BALL_R <= raquet.y)
	{
		printf("raquet");
		arka->vecBall.y = -arka->vecBall.y;
		arka->vecBall.x = -arka->vecBall.x + ratiox;
		if (arka->vecBall.x < BALL_R)
			arka->vecBall.x = -BALL_R;
		else if (arka->vecBall.x > BALL_R)
			arka->vecBall.x = BALL_R;
	}
}

static void		check_colision_blocs(t_draw *arka)
{
	t_bloc		*bloc;
	t_pos		ball;

	bloc = arka->blocs;
	ball = arka->ball;
	while (bloc != NULL)
	{
		if (ball.x + BALL_R >= bloc->pos.x && \
			ball.x - BALL_R <= bloc->pos.x + BLOC_X && \
			ball.y - BALL_R <= bloc->pos.y + BLOC_Y && \
			ball.y + BALL_R >= bloc->pos.y)
		{
			printf("%f %f == %f %f\n", ball.y, ball.x, bloc->pos.y, bloc->pos.x);
			if (ball.y >= bloc->pos.y && ball.y <= bloc->pos.y)
				arka->vecBall.x = -arka->vecBall.x;
			else
				arka->vecBall.y = -arka->vecBall.y;
			bloc->type--;
			if (bloc->type <= 0)
				rm_bloc(arka, bloc->pos.x, bloc->pos.x);
		}
		bloc = bloc->next;
	}
}

void			refresh_game(t_draw *arka)
{
	arka->ball.y += arka->vecBall.y;
	arka->ball.x += arka->vecBall.x;
	check_colision_window(arka);
	check_colision_raquet(arka);
	check_colision_blocs(arka);
	if (arka->blocs == NULL)
		arka->end = 1;
}
