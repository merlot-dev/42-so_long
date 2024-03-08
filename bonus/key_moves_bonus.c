/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:03:52 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 17:13:35 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_up(t_game *g)
{
	int		i;
	int		xy[2];
	t_img	cpm;

	if (g->m.maps[g->py - 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		xy[0] = g->px * g->dim + (g->dim / 22);
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmup, i);
			black_img(cpm);
			xy[1] = (g->py) * g->dim + (g->dim / 22) - i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmup, ++i % 4);
			xy[1] = g->py * g->dim + (g->dim / 22) - i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
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
		xy[0] = g->px * g->dim + (g->dim / 22);
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmdw, i);
			black_img(cpm);
			xy[1] = (g->py) * g->dim + (g->dim / 22) + i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmdw, ++i % 4);
			xy[1] = g->py * g->dim + (g->dim / 22) + i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
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
		xy[1] = g->py * g->dim + (g->dim / 22);
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmlf, i);
			black_img(cpm);
			xy[0] = (g->px) * g->dim + (g->dim / 22) - i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmlf, ++i % 4);
			xy[0] = g->px * g->dim + (g->dim / 22) - i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
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
		xy[1] = g->py * g->dim + (g->dim / 22);
		i = 0;
		while (i < 4)
		{
			cpm = get_sprite_n(g, g->el.pmrg, i);
			black_img(cpm);
			xy[0] = (g->px) * g->dim + (g->dim / 22) + i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
			cpm = get_sprite_n(g, g->el.pmrg, ++i % 4);
			xy[0] = g->px * g->dim + (g->dim / 22) + i * 11;
			x_img_to_win(*g, &cpm, xy, 1);
			mlx_do_sync(g->x.mlx);
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
	if (keycode == 126 && !g->gover)
		move_up(g);
	if (keycode == 125 && !g->gover)
		move_dw(g);
	if (keycode == 123 && !g->gover)
		move_lf(g);
	if (keycode == 124 && !g->gover)
		move_rg(g);
	if (g->px == g->m.endx && g->py == g->m.endy)
	{
		g->gover = 1;
		draw_gameover(g);
	}
	return (0);
}
