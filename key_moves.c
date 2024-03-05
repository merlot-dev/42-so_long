/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:54:44 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/05 23:21:14 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *g)
{
	int		i;
	int		xy[2];
	t_img	cpm;

	if (g->m.maps[g->py - 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmup, i);
			black_img(cpm);
			xy[1] = (g->py) * g->dim + 2 - i * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmup, (i + 1) % 4);
			xy[1] = g->py * g->dim + 2 - (i + 1) * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			i++;
			usleep(100000);
		}
		g->py--;
	}
	return (0);
}

int	move_dw(t_game *g)
{
	int		i;
	int		xy[2];
	t_img	cpm;

	if (g->m.maps[g->py + 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + 2;
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmdw, i);
			black_img(cpm);
			xy[1] = (g->py) * g->dim + 2 + i * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmdw, (i + 1) % 4);
			xy[1] = g->py * g->dim + 2 + (i + 1) * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			i++;
			usleep(100000);
		}
		g->py++;
	}
	return (0);
}

int	move_lf(t_game *g)
{
	int		i;
	int		xy[2];
	t_img	cpm;

	if (g->m.maps[g->py][g->px - 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[1] = g->py * g->dim + 2;
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmlf, i);
			black_img(cpm);
			xy[0] = (g->px) * g->dim + 2 - i * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmlf, (i + 1) % 4);
			xy[0] = g->px * g->dim + 2 - (i + 1) * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			i++;
			usleep(100000);
		}
		g->px--;
	}
	return (0);
}

int	move_rg(t_game *g)
{
	int		i;
	int		xy[2];
	t_img	cpm;

	if (g->m.maps[g->py][g->px + 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[1] = g->py * g->dim + 2;
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmrg, i);
			black_img(cpm);
			xy[0] = (g->px) * g->dim + 2 + i * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmrg, (i + 1) % 4);
			xy[0] = g->px * g->dim + 2 + (i + 1) * 11;
			x_img_to_win(*g, cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			i++;
			usleep(100000);
		}
		g->px++;
	}
	return (0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int	key_moves(int keycode, t_game *g)
{
	if (keycode == 13 && !g->gover)
		move_up(g);
	if (keycode == 6 && !g->gover)
		move_dw(g);
	if (keycode == 0 && !g->gover)
		move_lf(g);
	if (keycode == 1 && !g->gover)
		move_rg(g);
	if (g->px == g->m.endx && g->py == g->m.endy)
	{
		g->gover = 1;
		draw_gameover(g->x);
	}
	return (0);
}
