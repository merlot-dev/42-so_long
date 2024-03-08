/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coll_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:00:18 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 13:00:37 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
