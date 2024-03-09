/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:03:52 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/10 00:19:16 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_up(t_game *g)
{
	if (!g->pm.spr && g->m.maps[g->py - 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		g->pm.oy = - 1;
		g->pm.spr = &g->el.pmup;
	}
	return (0);
}

int	move_dw(t_game *g)
{
	if (!g->pm.spr && g->m.maps[g->py + 1][g->px] != '1')
	{
		draw_moves(*g, ++g->mv);
		g->pm.oy = 1;
		g->pm.spr = &g->el.pmdw;
	}
	return (0);
}

int	move_lf(t_game *g)
{
	if (!g->pm.spr && g->m.maps[g->py][g->px - 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		g->pm.ox = - 1;
		g->pm.spr = &g->el.pmlf;
	}
	return (0);
}

int	move_rg(t_game *g)
{
	if (!g->pm.spr && g->m.maps[g->py][g->px + 1] != '1')
	{
		draw_moves(*g, ++g->mv);
		g->pm.ox = 1;
		g->pm.spr = &g->el.pmrg;
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
	return (0);
}
