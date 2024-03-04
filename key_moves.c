/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:54:44 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/04 14:49:59 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *g)
{
	int	i;

	if (g->m.maps[g->py - 1][g->px] == '1')
		return (0);
	else
	{
    	g->mv++;
		i = 0;
		draw_pacman(g, g->py - 1, g->px);
	}
	return (0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int	key_moves(int keycode, t_game *g)
{
	int xy[2];

	if (keycode == 13 && !g->gover)
    {
		move_up(g);
    }
    xy[0] = SIDEX + 80;
    xy[1] = 140;
    draw_nbr(g->x, g->mv, xy, g->el);
	if (g->px == g->m.endx && g->py == g->m.endy)
	{
		g->gover = 1;
		draw_gameover(g->x);
	}
	return (0);
}
