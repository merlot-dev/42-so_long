/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fire_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:16:17 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/10 00:29:49 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_pc(t_game *g)
{
	int		xy[2];
	t_img	cpm;

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
	{
		g->px += g->pm.ox;
		g->py += g->pm.oy;
		g->pm.n = 0;
		g->pm.ox = 0;
		g->pm.oy = 0;
		g->pm.spr = NULL;
	}
	return (0);
}

int	draw_fire(t_game *g)
{
	static unsigned int	frame;
	t_img				cpm;
	int					xy[2];

	frame++;
	if (! (frame % 1024))
	{
		cpm = get_sprite_n(g, g->el.fire, (frame / 1024) % 5);
		xy[0] = 0;
		xy[1] = 0;
		x_img_to_win(*g, &cpm, xy, 1);
		if (g->pm.spr)
			move_pc(g);
	}
	if (!g->gover && g->px == g->m.endx && g->py == g->m.endy)
	{
		g->gover = 1;
		draw_gameover(g);
	}
	return (1);
}
