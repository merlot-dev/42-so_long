/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:54:44 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/04 16:53:18 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *g)
{
	int		i;
	int		xy[2];
	int		sxy[2];
	t_img	cpm;

	if (g->m.maps[g->py - 1][g->px] == '1')
		return (0);
	else
	{
    	g->mv++;
		sxy[0] = 40;
		sxy[1] = 40;
		i = 3;
		while (i >= 0)
		{
			draw_black(g, g->py, g->px, g->el);
			xy[0] = i * 40;
			xy[1] = 0;
			cpm = cut_img(g->x, g->el.pmup, xy, sxy);
			xy[0] = g->px * g->dim + 2;
			xy[1] = (g->py - 1) * g->dim + 2 + i * 10;
			mlx_put_image_to_window(g->x.mlx, g->x.win, g->el.black.img, xy[0], xy[1]);
			mlx_put_image_to_window(g->x.mlx, g->x.win, cpm.img, xy[0], xy[1]);
			mlx_destroy_image(g->x.mlx, cpm.img);
			mlx_do_sync(g->x.mlx);
			i--;
			usleep(500000);
		}
		g->py--;
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
