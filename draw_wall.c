/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:34:07 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/07 15:42:20 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_wall(t_game *g, int row, int col, t_mapel el)
{
	int	xy[2];

	xy[0] = col * g->dim;
	xy[1] = row * g->dim;
	if (row < (g->m.rows - 1) && g->m.maps[row + 1][col] == '1'
		&& col < (g->m.cols - 1) && g->m.maps[row + 1][col + 1] != '1')
		x_img_to_win(*g, &el.cr[2], xy, 0);
	if (row < (g->m.rows - 1) && g->m.maps[row + 1][col] == '1'
		&& col > 0 && g->m.maps[row + 1][col - 1] != '1')
		x_img_to_win(*g, &el.cr[3], xy, 0);
	if (row > 0 && g->m.maps[row - 1][col] == '1'
		&& col < (g->m.cols - 1) && g->m.maps[row - 1][col + 1] != '1')
		x_img_to_win(*g, &el.cr[1], xy, 0);
	if (row > 0 && g->m.maps[row - 1][col] == '1'
		&& col > 0 && g->m.maps[row - 1][col - 1] != '1')
		x_img_to_win(*g, &el.cr[0], xy, 0);
	if (!col || g->m.maps[row][col - 1] != '1')
		x_img_to_win(*g, &el.wl[0], xy, 0);
	if (col == (g->m.cols -1) || g->m.maps[row][col + 1] != '1')
		x_img_to_win(*g, &el.wl[1], xy, 0);
	if (!row || g->m.maps[row - 1][col] != '1')
		x_img_to_win(*g, &el.wl[2], xy, 0);
	if (row == (g->m.rows -1) || g->m.maps[row + 1][col] != '1')
		x_img_to_win(*g, &el.wl[3], xy, 0);
	return (0);
}
