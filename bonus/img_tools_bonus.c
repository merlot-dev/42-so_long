/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:03:09 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/08 13:03:22 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	get_xpm_img(t_mlx mx, char *fn)
{
	t_img	rim;

	rim.addr = NULL;
	rim.img = mlx_xpm_file_to_image(mx.mlx, fn, &rim.w, &rim.h);
	if (!rim.img)
		return (rim);
	rim.addr = mlx_get_data_addr(rim.img, &rim.bpp, &rim.ll, &rim.end);
	return (rim);
}

t_img	cut_img(t_mlx mx, t_img im, int st[2], int sz[2])
{
	t_img	cuti;
	int		y;
	char	*dst;

	cuti.addr = NULL;
	if (!im.addr)
		return (cuti);
	if (im.w < (st[0] + sz[0]) || im.h < (st[1] + sz[1]))
		return (cuti);
	cuti.img = mlx_new_image(mx.mlx, sz[0], sz[1]);
	if (!cuti.img)
		return (cuti);
	cuti.addr = mlx_get_data_addr(cuti.img, &cuti.bpp, &cuti.ll, &cuti.end);
	y = 0;
	while (y < sz[1])
	{
		dst = im.addr + (y + st[1]) * im.ll + st[0] * (im.bpp / 8);
		ft_memcpy(cuti.addr + (y * cuti.ll), dst, sz[0] * im.bpp / 8);
		y++;
	}
	cuti.w = sz[0];
	cuti.h = sz[1];
	return (cuti);
}

void	black_img(t_img im)
{
	int	i;
	int	*p;

	i = 0;
	p = (int *)im.addr;
	while (i++ < im.w * im.h)
	{
		if (*p != (int) 0xff000000)
			*p = 0;
		p++;
	}
}

t_img	get_sprite_n(t_game *g, t_img sp, int n)
{
	t_img	rim;
	int		xy[2];
	int		sxy[2];

	sxy[0] = sp.h;
	sxy[1] = sp.h;
	xy[0] = n * sp.h;
	xy[1] = 0;
	rim = cut_img(g->x, sp, xy, sxy);
	return (rim);
}
