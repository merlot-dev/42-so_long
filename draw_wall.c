/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:34:07 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/03 01:06:40 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int draw_wall(t_game *g, int row, int col, t_mapel el)
{
	int	 x;
	int	 y;

	x = col * g->dim;
	y = row * g->dim;
	if (!col || g->m.maps[row][col - 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.wl[0].img, x, y);
	if (col == (g->m.cols -1) || g->m.maps[row][col + 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.wl[1].img, x, y);
	if (!row || g->m.maps[row - 1][col] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.wl[2].img, x, y);
	if (row == (g->m.rows -1) || g->m.maps[row + 1][col] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.wl[3].img, x, y);
	if (row < (g->m.rows - 1) && g->m.maps[row + 1][col] == '1'
		&& col < (g->m.cols - 1) && g->m.maps[row + 1][col + 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.cr[2].img, x, y);
	if (row < (g->m.rows - 1) && g->m.maps[row + 1][col] == '1'
		&& col > 0  && g->m.maps[row + 1][col - 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.cr[3].img, x, y);
	if (row > 0 && g->m.maps[row - 1][col] == '1'
		&& col < (g->m.cols - 1) && g->m.maps[row - 1][col + 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.cr[1].img, x, y);
	if (row > 0 && g->m.maps[row - 1][col] == '1'
		&& col > 0  && g->m.maps[row - 1][col - 1] != '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, el.cr[0].img, x, y);

	return (0);
}
