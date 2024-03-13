/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anime_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:16:17 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/14 00:27:30 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_pc_end(t_game *g)
{
	if (g->m.maps[g->py][g->px] == 'C')
	{
		g->m.coll--;
		g->m.maps[g->py][g->px] = 'F';
	}
	g->px += g->pm.ox;
	g->py += g->pm.oy;
	g->pm.n = 0;
	g->pm.ox = 0;
	g->pm.oy = 0;
	g->pm.spr = NULL;
	if (g->px != g->m.endx || g->py != g->m.endy)
		draw_exit(g, g->m.endy, g->m.endx);
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

int	draw_dead(t_game *g)
{
	t_img				cpm;
	int					xy[2];

	if (g->dead && g->dead < 11)
	{
		cpm = get_sprite_n(g, g->el.dead, g->dead++);
		xy[0] = g->px * g->dim + g->dim / 22;
		xy[1] = g->py * g->dim + g->dim / 22;
		x_img_to_win(*g, &cpm, xy, 1);
	}
	return (0);
}

int	sl_anime(t_game *g)
{
	static unsigned int	frame;

	frame++;
	if (! (frame % FRAMES))
	{
		draw_fire(g, (frame / FRAMES) % 5);
		move_pc(g);
		draw_dead(g);
	}
	if (!g->gover && g->m.maps[g->py][g->px] == 'F')
	{
		g->dead = 1;
		g->m.maps[g->py][g->px] = 'C';
	}
	if (!g->gover && ((g->px == g->m.endx && g->py == g->m.endy && !g->m.coll)
		|| g->dead))
		g->gover = draw_gameover(g) + 1;
	return (0);
}
