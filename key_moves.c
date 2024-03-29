/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:54:44 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/14 00:10:02 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *g)
{
	int		xy[2];

	if (g->m.maps[g->py - 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		xy[1] = g->py * g->dim + 2;
		x_img_to_win(*g, &g->el.black, xy, 0);
		xy[1] = (--g->py) * g->dim + 2;
		x_img_to_win(*g, &g->el.pacman, xy, 0);
	}
	return (0);
}

int	move_dw(t_game *g)
{
	int		xy[2];

	if (g->m.maps[g->py + 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		xy[1] = g->py * g->dim + 2;
		x_img_to_win(*g, &g->el.black, xy, 0);
		xy[1] = (++g->py) * g->dim + 2;
		x_img_to_win(*g, &g->el.pacman, xy, 0);
	}
	return (0);
}

int	move_lf(t_game *g)
{
	int		xy[2];

	if (g->m.maps[g->py][g->px - 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		xy[1] = g->py * g->dim + 2;
		x_img_to_win(*g, &g->el.black, xy, 0);
		xy[0] = (--g->px) * g->dim + 2;
		x_img_to_win(*g, &g->el.pacman, xy, 0);
	}
	return (0);
}

int	move_rg(t_game *g)
{
	int		xy[2];

	if (g->m.maps[g->py][g->px + 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		xy[1] = g->py * g->dim + 2;
		x_img_to_win(*g, &g->el.black, xy, 0);
		xy[0] = (++g->px) * g->dim + 2;
		x_img_to_win(*g, &g->el.pacman, xy, 0);
	}
	return (0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int	key_moves(int keycode, t_game *g)
{
	if (keycode == 126 && !g->gover)
		move_up(g);
	if (keycode == 125 && !g->gover)
		move_dw(g);
	if (keycode == 123 && !g->gover)
		move_lf(g);
	if (keycode == 124 && !g->gover)
		move_rg(g);
	if (g->m.maps[g->py][g->px] == 'C')
	{
		g->m.coll--;
		g->m.maps[g->py][g->px] = 'c';
	}
	if (g->px == g->m.endx && g->py == g->m.endy && !g->m.coll)
	{
		g->gover = 1;
		draw_gameover(g);
	}
	if (g->px != g->m.endx || g->py != g->m.endy)
		draw_exit(g, g->m.endy, g->m.endx);
	return (0);
}
