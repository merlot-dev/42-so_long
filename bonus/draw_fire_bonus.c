/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:16:17 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:05:46 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_pc_end(t_game *g)
{
	if (g->m.maps[g->py][g->px] == 'C')
		g->m.maps[g->py][g->px] = 'F';
	g->px += g->pm.ox;
	g->py += g->pm.oy;
	g->pm.n = 0;
	g->pm.ox = 0;
	g->pm.oy = 0;
	g->pm.spr = NULL;
}

int	move_pc(t_game *g)
{
	int		xy[2];
	t_img	cpm;

	if (g->pm.spr)
	{
		xy[0] = g->px * g->dim + (g->dim / 22);
		xy[0] += g->pm.ox * g->pm.n * (g->dim / 4);
		xy[1] = (g->py) * g->dim + (g->dim / 22);
		xy[1] += g->pm.oy * g->pm.n * (g->dim / 4);
		cpm = get_sprite_n(g, *(g->pm.spr), g->pm.n);
		black_img(cpm);
		x_img_to_win(*g, &cpm, xy, 1);
		cpm = get_sprite_n(g, *(g->pm.spr), ++g->pm.n % 4);
		xy[0] += g->pm.ox * (g->dim / 4);
		xy[1] += g->pm.oy * (g->dim / 4);
		x_img_to_win(*g, &cpm, xy, 1);
		if (g->pm.n == 4)
			move_pc_end(g);
	}
	return (0);
}

int	draw_fire(t_game *g, int n)
{
	t_img				cpm;
	int					xy[2];

	cpm = get_sprite_n(g, g->el.fire, n);
	xy[1] = g->dim + g->dim / 22;
	while (xy[1] < (g->m.rows - 1) * g->dim)
	{
		xy[0] = g->dim + g->dim / 22;
		while (xy[0] < (g->m.cols - 1) * g->dim)
		{
			if (g->m.maps[xy[1] / g->dim][xy[0] / g->dim] == 'F')
				x_img_to_win(*g, &cpm, xy, 0);
			xy[0] += g->dim;
		}
		xy[1] += g->dim;
	}
	x_destroy_img(*g, &cpm);
	return (0);
}

int	sl_anime(t_game *g)
{
	static unsigned int	frame;
	t_img				cpm;
	int					xy[2];

	frame++;
	if (! (frame % 1024))
	{
		draw_fire(g, (frame / 1024) % 5);
		move_pc(g);
		if (g->dead)
		{
			cpm = get_sprite_n(g, g->el.dead, g->dead++);
			xy[0] = g->px *g->dim + g->dim / 22;
			xy[1] = g->py *g->dim + g->dim / 22;;
			x_img_to_win(*g, &cpm, xy, 1);
			g->dead *= (g->dead != 11);
		}
	}
	if (!g->gover && g->m.maps[g->py][g->px] == 'F')
	{
		g->dead =  1;
		g->m.maps[g->py][g->px] = 'C';
	}
	if (!g->gover && ((g->px == g->m.endx && g->py == g->m.endy) || g->dead))
		g->gover = draw_gameover(g) + 1;
	return (0);
}
