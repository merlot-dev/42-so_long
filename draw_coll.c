/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:54:57 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 00:28:30 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_coll(t_game *g, int row, int col, t_mapel el)
{
	int	i;
	int	x;
	int	y;

	x = col * g->dim + 2;
	y = row * g->dim + 2;
	i = g->mv++ % 4;
	if (i == 0)
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.blinky.img, x, y);
	else if (i == 1)
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.inky.img, x, y);
	else if (i == 2)
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.clyde.img, x, y);
	else if (i == 3)
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.pinky.img, x, y);
	return (0);
}
