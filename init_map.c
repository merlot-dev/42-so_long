/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:43:29 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/11 12:41:37 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_game *g)
{
	if (g->m.cols > 40 || g->m.rows > 33)
		return (sl_error_free(&g->m, "Map is OK but big to be playable\n"));
	g->dim = CELLDIM;
	g->x.winx = g->dim * g->m.cols + 280;
	g->x.winy = g->dim * g->m.rows;
	if (g->x.winy < 300)
		g->x.winy = 300;
	return (0);
}
